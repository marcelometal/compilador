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
   do scanner no compilador.
   */

//biblioteca com as declarações e protótipos
#include "definicoesC3E.h"
#include "constantes.h"
#include <string.h>

/**
 * Função usada para criar uma pilha para a geracao de codigo
 *
 * @since 21/11/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void criaPilha(tipoPilha *p)
{
    p->fundo = (apontGeral) malloc(sizeof(celulaGeral));
    p->topo = p->fundo;
    p->topo->prox = NULL;
    p->topo->ant = NULL;
}

/**
 * Função usada para empilhar na pilha de geracao de codigo
 *
 * @since 21/11/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void empilha(tipoNome x, tipoPilha *p)
{
    apontGeral novaCelula;
    novaCelula = (apontGeral) malloc(sizeof(celulaGeral));
    novaCelula->item = x;
    novaCelula->prox = NULL;
    novaCelula->ant = p->topo;
    p->topo->prox = novaCelula;
    p->topo = novaCelula;
}


/**
 * Função usada para desempilhar a pilha de geracao de codigo
 *
 * @since 21/11/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void desempilha(tipoPilha *p)
{
    apontGeral q = p->topo;
    p->topo = q->ant;
    p->topo->prox = NULL;
    free(q);
}

/**
 * Função usada para concatenar um valor inteiro com uma string retornando uma nova string
 *
 * @since 21/11/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
char *concatena(char buffer[25], int numero)
{
    char *strValor = (char *) malloc(25 * sizeof(char));
    char *strNum = (char *) malloc(25 * sizeof(char));
    strcpy(strValor, buffer);
    sprintf(strNum, "%d", numero);
    strcat(strValor, strNum);
    return strValor;
}

/**
 * Função usada para gerar uma variavel temporaria
 *
 * @since 21/11/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
char *geraTemp()
{
    contTemp++;
    return concatena("temp", contTemp - 1);
}

/**
 * Função usada para retornar a variavel que será inserida na pilha
 *
 * @since 21/11/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
tipoNome retornarTipoNome(char lexema[160])
{
    tipoNome x;
    strcpy(x.lexema, lexema);
    return x;
}

/**
 * Função usada para gerar o codigo de 3 enderecos
 *
 * @since 21/11/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void geraCodigo(FILE *arqC3E, int acao, tipoPilha *pLabel,
        tipoPilha *pNomes, tipoPilha *pParametros,
        char lexema[160])
{
    apontGeral p;
    switch (acao) {
        case ACAOINIT:
            {
                empilha(retornarTipoNome("init"), pNomes);
                break;
            }
        case ACAONOMSUBPROGRAMA:
            {
                validaListaPar = -1;
                break;
            }
        case ACAOBLOCO:
            {
                LABEL(pNomes->topo->item.lexema)
                    desempilha(pNomes);
                break;
            }
        case ACAOPARAMETROSFUNCOES:
            {
                validaListaPar = 1;
                break;
            }
        case ACAONAOPARAMETROS:
            {
                validaListaPar = 0;
                break;
            }
        case ACAOGETPAR:
            {
                p = pParametros->fundo->prox;
                while (p != NULL) {
                    GETPAR(p->item.lexema)
                        p = p->prox;
                }
                while (pParametros->topo != pParametros->fundo)
                    desempilha(pParametros);
                break;
            }
        case ACAORETORNOPROCEDURE:
            {
                RETURN("")
                    break;
            }
        case ACAORETORNOFUNCAO:
            {
                RETURN(lexema)
                    break;
            }
        case ACAOATRIBUICAO1:
            {
                validaListaPar = -1;
                break;
            }
        case ACAOATRIBUICAO2:
            {
                VARIAVEL(pNomes->topo->item.lexema)
                    ATRB VARIAVEL2(lexema) veriAtribuicao = 1;
                break;
            }
        case ACAOATRIBUICAO3:
            {
                if (!leituraRead && !leituraReadln && !escritaWrite
                        && !escritaWriteln) {
                    if (!veriAtribuicao) {
                        CALL VARIAVEL2(pNomes->topo->
                                item.lexema)
                    }
                    veriAtribuicao = 0;
                    desempilha(pNomes);
                }
                break;
            }
        case ACAOPARAMETRO1:
            {
                empilha(retornarTipoNome(lexema), pParametros);
                break;
            }
        case ACAOPUTPAR:
            {
                p = pParametros->fundo->prox;
                while (p != NULL) {
                    PUTPAR(p->item.lexema)
                        p = p->prox;
                }
                while (pParametros->topo != pParametros->fundo)
                    desempilha(pParametros);
                if (!leituraRead && !leituraReadln && !escritaWrite
                        && !escritaWriteln)
                    CALL VARIAVEL2(pNomes->topo->
                            item.lexema) break;
            }
        case ACAOCOMANDOIF1:
            {
                empilha(retornarTipoNome
                        (concatena("FIMIF", contLabelIf)), pLabel);
                empilha(retornarTipoNome
                        (concatena("ELSE_IF", contLabelIf)),
                        pLabel);
                COMPARACAO(lexema)
                    DESVIO(pLabel->topo->item.lexema)
                    contLabelIf++;
                break;
            }
        case ACAOCOMANDOIF2:
            {
                DESVIO(pLabel->topo->ant->item.lexema)
                    LABEL(pLabel->topo->item.lexema)
                    desempilha(pLabel);
                break;
            }
        case ACAOCOMANDOELSE1:
            {
                LABEL(pLabel->topo->item.lexema)
                    desempilha(pLabel);
                contLabelIf = 1;
                break;
            }
        case ACAOCOMANDOREPEAT1:
            {
                empilha(retornarTipoNome
                        (concatena("REPEAT", contLabelRepeat)),
                        pLabel);
                empilha(retornarTipoNome
                        (concatena("FIMREPEAT", contLabelRepeat)),
                        pLabel);
                LABEL(pLabel->topo->ant->item.lexema)
                    contLabelRepeat++;
                break;
            }
        case ACAOCOMANDOREPEAT2:
            {
                COMPARACAO(lexema)
                    DESVIO(pLabel->topo->item.lexema)
                    DESVIO(pLabel->topo->ant->item.lexema)
                    LABEL(pLabel->topo->item.lexema)
                    desempilha(pLabel);
                desempilha(pLabel);
                contLabelRepeat = 1;
                break;
            }
        case ACAOCOMANDOWHILE1:
            {
                empilha(retornarTipoNome
                        (concatena("WHILE", contLabelWhile)),
                        pLabel);
                empilha(retornarTipoNome
                        (concatena("FIMWHILE", contLabelWhile)),
                        pLabel);
                LABEL(pLabel->topo->ant->item.lexema)
                    contLabelWhile++;
                break;
            }
        case ACAOCOMANDOWHILE2:
            {
                COMPARACAO(lexema)
                    DESVIO(pLabel->topo->item.lexema)
                    break;
            }
        case ACAOCOMANDOWHILE3:
            {
                DESVIO(pLabel->topo->ant->item.lexema)
                    LABEL(pLabel->topo->item.lexema)
                    desempilha(pLabel);
                desempilha(pLabel);
                contLabelWhile = 1;
                break;
            }
        case ACAOCOMANDOFOR1:
            {
                validaListaPar = -1;
                empilha(retornarTipoNome
                        (concatena("FOR", contLabelFor)), pLabel);
                empilha(retornarTipoNome
                        (concatena("FIMFOR", contLabelFor)),
                        pLabel);
                contLabelFor++;
                break;
            }
        case ACAOCOMANDOFOR2:
            {
                VARIAVEL(pNomes->topo->item.lexema)
                    ATRB VARIAVEL2(lexema)
                    LABEL(pLabel->topo->ant->item.lexema) break;
            }
        case ACAOCOMANDOFOR3:
            {
                COMPARACAO2(pNomes->topo->item.lexema, '>', lexema)
                    DESVIO(pLabel->topo->item.lexema)
                    break;
            }
        case ACAOCOMANDOFOR4:
            {
                VARIAVEL(pNomes->topo->item.lexema)
                    ATRB VARIAVEL(pNomes->topo->item.lexema)
                    SINAL('+');
                VARIAVEL2("1")
                    DESVIO(pLabel->topo->ant->item.lexema)
                    LABEL(pLabel->topo->item.lexema)
                    desempilha(pNomes);
                desempilha(pLabel);
                desempilha(pLabel);
                contLabelFor = 0;
                break;
            }
        case ACAOCOMANDOREAD1:
            {
                leituraRead = 1;
                break;
            }
        case ACAOCOMANDOREAD2:
            {
                CALL IREAD validaListaPar = 0;
                leituraRead = 0;
                break;
            }
        case ACAOCOMANDOREADLN1:
            {
                leituraReadln = 1;
                break;
            }
        case ACAOCOMANDOREADLN2:
            {
                CALL IREAD validaListaPar = 0;
                leituraReadln = 0;
                break;
            }
        case ACAOCOMANDOWRITE1:
            {
                escritaWrite = 1;
                break;
            }
        case ACAOCOMANDOWRITE2:
            {
                CALL IWRITE validaListaPar = 0;
                escritaWrite = 0;
                break;
            }
        case ACAOCOMANDOWRITELN1:
            {
                escritaWriteln = 1;
                break;
            }
        case ACAOCOMANDOWRITELN2:
            {
                CALL IWRITE validaListaPar = 0;
                escritaWriteln = 0;
                break;
            }
        case ACAOHALT:
            {
                HALT break;
            }
    }
}
