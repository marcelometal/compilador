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

//biblioteca com as declarações e protótipos
#include "palavraChave.h"

/**
 * Cria uma chave hash para a inserção dos tokens na lista
 *
 * @since
 * @author Erix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int hashing(char lexema[160])
{
    int i = 0, soma = 0;
    for (i = 0; i < strlen(lexema); i++)
        soma += lexema[i];
    return (soma % MAXPC);
}


/**
 * Insere cada palavra-chave na lista de palavras-chave
 *
 * @since
 * @author Erix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void inserirPalavraChave()
{
    pChave x;
    strcpy(x.lexema, "PROGRAM");
    x.classe = PROGRAM;
    inserePc(x, &listaPc[hashing("PROGRAM")]);
    strcpy(x.lexema, "CONST");
    x.classe = CONST;
    inserePc(x, &listaPc[hashing("CONST")]);
    strcpy(x.lexema, "TYPE");
    x.classe = TYPE;
    inserePc(x, &listaPc[hashing("TYPE")]);
    strcpy(x.lexema, "VAR");
    x.classe = VAR;
    inserePc(x, &listaPc[hashing("VAR")]);
    strcpy(x.lexema, "BEGIN");
    x.classe = BEGIN;
    inserePc(x, &listaPc[hashing("BEGIN")]);
    strcpy(x.lexema, "END");
    x.classe = END;
    inserePc(x, &listaPc[hashing("END")]);
    strcpy(x.lexema, "PROCEDURE");
    x.classe = PROCEDURE;
    inserePc(x, &listaPc[hashing("PROCEDURE")]);
    strcpy(x.lexema, "FUNCTION");
    x.classe = FUNCTION;
    inserePc(x, &listaPc[hashing("FUNCTION")]);
    strcpy(x.lexema, "INTEGER");
    x.classe = INTEGER;
    inserePc(x, &listaPc[hashing("INTEGER")]);
    strcpy(x.lexema, "REAL");
    x.classe = REAL;
    inserePc(x, &listaPc[hashing("REAL")]);
    strcpy(x.lexema, "CHAR");
    x.classe = CHAR;
    inserePc(x, &listaPc[hashing("CHAR")]);
    strcpy(x.lexema, "BOOLEAN");
    x.classe = BOOLEAN;
    inserePc(x, &listaPc[hashing("BOOLEAN")]);
    strcpy(x.lexema, "CADEIA");
    x.classe = CADEIA;
    inserePc(x, &listaPc[hashing("CADEIA")]);
    strcpy(x.lexema, "TRUE");
    x.classe = TRUE;
    inserePc(x, &listaPc[hashing("TRUE")]);
    strcpy(x.lexema, "FALSE");
    x.classe = FALSE;
    inserePc(x, &listaPc[hashing("FALSE")]);
    strcpy(x.lexema, "IF");
    x.classe = IF;
    inserePc(x, &listaPc[hashing("IF")]);
    strcpy(x.lexema, "THEN");
    x.classe = THEN;
    inserePc(x, &listaPc[hashing("THEN")]);
    strcpy(x.lexema, "ELSE");
    x.classe = ELSE;
    inserePc(x, &listaPc[hashing("ELSE")]);
    strcpy(x.lexema, "WHILE");
    x.classe = WHILE;
    inserePc(x, &listaPc[hashing("WHILE")]);
    strcpy(x.lexema, "DO");
    x.classe = DO;
    inserePc(x, &listaPc[hashing("DO")]);
    strcpy(x.lexema, "REPEAT");
    x.classe = REPEAT;
    inserePc(x, &listaPc[hashing("REPEAT")]);
    strcpy(x.lexema, "UNTIL");
    x.classe = UNTIL;
    inserePc(x, &listaPc[hashing("UNTIL")]);
    strcpy(x.lexema, "FOR");
    x.classe = FOR;
    inserePc(x, &listaPc[hashing("FOR")]);
    strcpy(x.lexema, "NOT");
    x.classe = NOT;
    inserePc(x, &listaPc[hashing("NOT")]);
    strcpy(x.lexema, "TO");
    x.classe = TO;
    inserePc(x, &listaPc[hashing("TO")]);
    strcpy(x.lexema, "WRITE");
    x.classe = WRITE;
    inserePc(x, &listaPc[hashing("WRITE")]);
    strcpy(x.lexema, "WRITELN");
    x.classe = WRITELN;
    inserePc(x, &listaPc[hashing("WRITELN")]);
    strcpy(x.lexema, "READ");
    x.classe = READ;
    inserePc(x, &listaPc[hashing("READ")]);
    strcpy(x.lexema, "READLN");
    x.classe = READLN;
    inserePc(x, &listaPc[hashing("READLN")]);
    strcpy(x.lexema, "MOD");
    x.classe = MULTOP;
    inserePc(x, &listaPc[hashing("MOD")]);
    strcpy(x.lexema, "DIV");
    x.classe = MULTOP;
    inserePc(x, &listaPc[hashing("DIV")]);
    strcpy(x.lexema, "AND");
    x.classe = MULTOP;
    inserePc(x, &listaPc[hashing("AND")]);
    strcpy(x.lexema, "OR");
    x.classe = ADDOP;
    inserePc(x, &listaPc[hashing("OR")]);
    INIPALAVRACHAVE = 0;
}

/**
 * Cria a lista de palavras-chave inicializando as posições
 *
 * @since
 * @author Erix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void inicializaPc()
{
    int i;
    for (i = 0; i < MAXPC; i++)
        criaListaPc(&listaPc[i]);
}


/**
 * Cria uma listata pChave vazia
 *
 * @since
 * @author Erix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void criaListaPc(tipoListaPc *l)
{
    l->primeiro = (apontador) malloc(sizeof(celPc));
    l->ultimo = l->primeiro;
    l->primeiro->prox = NULL;
}


/**
 * Função usada para inserir uma palavra-chave na lista
 *
 * @since
 * @author Erix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void inserePc(pChave x, tipoListaPc *l)
{
    l->ultimo->prox = (apontador) malloc(sizeof(celPc));
    l->ultimo = l->ultimo->prox;
    l->ultimo->item = x;
    l->ultimo->prox = NULL;
}


/**
 * Exibi a lista de palavrasFunção usada para inserir uma palavra-chave na lista
 *
 * @since
 * @author Erix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void imprimeLista()
{
    int k;
    for (k = 0; k < MAXPC; k++) {
        apontador p = listaPc[k].primeiro;
        while (p->prox != NULL)
            p = p->prox;
    }
}


/**
 * Pesquisa uma palavra-chave na lista de palavras-chave
 *
 * @since
 * @author Erix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int pesquisaPc(char lexema[160])
{
    pChave x;
    int j = 0, i = hashing(lexema);
    apontador p = listaPc[i].primeiro;
    int achou = 1;
    x.classe = FINALLISTAPC;
    while (p->prox != NULL && achou) {
        j++;
        achou = strcmp(p->prox->item.lexema, lexema);
        if (achou)
            p = p->prox;
    }
    if (p->prox != NULL)
        return p->prox->item.classe;
    return ID;
}
