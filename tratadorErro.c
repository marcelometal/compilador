/**
 * Copyright (c) 2003, Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * Copyright (c) 2003, Marcelo Jorge Vieira <metal@alucinados.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation, either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
   Neste arquivo está as funções para manipulação
   de erros no compilador.
   */

//biblioteca com as declarações e protótipos
#include "tratadorErro.h"
#include <stdio.h>
#include <string.h>


/**
 * Função usada para criar um lista de erros
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void criaListaErro(listaErro *e)
{
    e->primeiro = (apontErro) malloc(sizeof(cErro));
    e->ultimo = e->primeiro;
    e->primeiro->prox = NULL;
}

/**
 * Função usada para verificar se a lista de erros está vazia
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int vazia(listaErro e)
{
    return e.ultimo == e.primeiro;
}

/**
 * Função usada para inserir um erro na lista
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void inserirErro(tErro x, listaErro *e)
{
    apontErro p, q, novaCelula;
    p = e->primeiro;
    q = e->primeiro->prox;

    while (q != NULL && q->item.linha < x.linha) {
        p = q;
        q = q->prox;
    }
    novaCelula = (apontErro) malloc(sizeof(cErro));
    novaCelula->item = x;
    novaCelula->prox = q;
    p->prox = novaCelula;
    if (q == NULL)
        e->ultimo = novaCelula;
}


/* Função usada para exibir a lista de erros
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void imprimirErro(listaErro e)
{
    int i = 0;
    apontErro p = e.primeiro;
    for (i = 0; i < 110; i++) {
        if (i % 2)
            printf("=");
        else
            printf("-");
    }
    printf("\n\t\t\t\tMensagens de Erro\n");
    for (i = 0; i < 110; i++) {
        if (i % 2)
            printf("=");
        else
            printf("-");
    }
    ENTER;
    ENTER;
    printf("Numero\t\t\t\tMensagens\t\t\tLinha");
    ENTER;
    ENTER;
    i = 1;
    while (p->prox != NULL) {
        printf("%d\t\t\t\t%s\t\t\t%d", i, p->prox->item.mensagem,
                p->prox->item.linha);
        ENTER;
        p = p->prox;
        i++;
    }
}

/**
 * Função usada para recuperar o erro ocorrido
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
tErro recuperarErro(int linha, int codErro, char lexema[160])
{
    tErro e;
    e.linha = linha;
    e.codErro = codErro;

    switch (codErro) {
        case -2:
            {
                strcpy(e.mensagem,
                        "Erro Léxico: Isto não e um numero: ");
                strcat(e.mensagem, lexema);
                break;
            }
        case -3:
            {
                strcpy(e.mensagem,
                        "Erro Léxico: Caractere Invalido: ");
                strcat(e.mensagem, lexema);
                break;
            }
        case -4:
            {
                strcpy(e.mensagem,
                        "Erro Léxico: O literal nao foi fechado ['] ");
                break;
            }
        case -6:
            {
                strcpy(e.mensagem,
                        "Erro Léxico: O comentario não foi fechado '}' ");
                break;
            }
    }
    contErroLexico++;
    return e;
}
