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
   do parser no compilador.
   */

#include "parser.h"
#include "definicoesC3E.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Função usada para criar uma pilha vazia para o analisador sintatico preditivo
 *
 * @since 09/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void criaPilhaASP(tipoPilhaASP *p)
{
    p->fundo = (apontASP) malloc(sizeof(celulaASP));
    p->topo = p->fundo;
    p->topo->prox = NULL;
}

/**
 * Função usada para criar uma pilha vazia para o analisador sintatico com precedencia de operadores
 *
 * @since 09/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void criaPilhaASPO(tipoPilhaASPO *p)
{
    p->fundo = (apontASPO) malloc(sizeof(celulaASPO));
    p->topo = p->fundo;
    p->topo->prox = NULL;
    p->topo->ant = NULL;
}

/**
 * Função usada para empilhar um token para o analisador sintatico preditivo
 *
 * @since 09/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void empilhaASP(tipoASP x, tipoPilhaASP *p)
{
    p->topo->prox = (apontASP) malloc(sizeof(celulaASP));
    p->topo = p->topo->prox;
    p->topo->item = x;
    p->topo->prox = NULL;
}

/**
 * Função usada para empilhar um token para o analisador sintatico com precedencia de operadores
 *
 * @since 09/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void empilhaASPO(tipoASPO x, tipoPilhaASPO *p)
{
    apontASPO novaCelula;
    novaCelula = (apontASPO) malloc(sizeof(celulaASPO));
    novaCelula->item = x;
    novaCelula->prox = NULL;
    novaCelula->ant = p->topo;
    p->topo->prox = novaCelula;
    p->topo = novaCelula;
}

/**
 * Função usada para desempilhar um token para o analisador sintatico preditivo
 *
 * @since 09/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void desempilhaASP(tipoPilhaASP *p)
{
    apontASP q = p->fundo;
    apontASP anterior = NULL;
    while (q != p->topo) {
        anterior = q;
        q = q->prox;
    }
    anterior->prox = p->topo->prox;
    p->topo = anterior;
    free(q);
}

/**
 * Função usada para desempilhar um token para o analisador sintatico com precedencia de operadores
 *
 * @since 09/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void desempilhaASPO(tipoPilhaASPO *p)
{
    apontASPO q = p->topo;
    p->topo = q->ant;
    p->topo->prox = NULL;
    free(q);
}

/**
 * Função usada para retorna a coluna da matrisAcao a partir da classe de entrada
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int retornarColunaMatrizAcao(int classe)
{
    switch (classe) {
        case PROGRAM:
            return 0;
        case CONST:
            return 1;
        case TYPE:
            return 2;
        case VAR:
            return 3;
        case BEGIN:
            return 4;
        case END:
            return 5;
        case PROCEDURE:
            return 6;
        case FUNCTION:
            return 7;
        case INTEGER:
            return 8;
        case REAL:
            return 9;
        case CHAR:
            return 10;
        case BOOLEAN:
            return 11;
        case CADEIA:
            return 12;
        case IF:
            return 13;
        case THEN:
            return 14;
        case ELSE:
            return 15;
        case REPEAT:
            return 16;
        case UNTIL:
            return 17;
        case WHILE:
            return 18;
        case DO:
            return 19;
        case FOR:
            return 20;
        case TO:
            return 21;
        case READLN:
            return 22;
        case READ:
            return 23;
        case WRITE:
            return 24;
        case WRITELN:
            return 25;
        case PONTO:
            return 26;
        case VIRGULA:
            return 27;
        case PONTOVIRGULA:
            return 28;
        case DOISPONTOS:
            return 29;
        case ABREPAR:
            return 30;
        case FECHAPAR:
            return 31;
        case ID:
            return 32;
        case RELOP:
            return 33;
        case ADDOP:
            return 34;
        case MULTOP:
            return 35;
        case NOT:
            return 36;
        case NUM:
            return 37;
        case LITERAL:
            return 38;
        case ATRIB:
            return 39;
        case FINALARQ:
            return 40;
    }
    return -1;
}

/**
 * Função usada para retorna a linha da matrisAcao a partir dos não-terminais
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int retornarLinhaMatrizAcao(int nTerminal)
{
    switch (nTerminal) {
        case PROGRAMA:
            return 0;
        case BLOCO:
            return 1;
        case BLOCO1:
            return 2;
        case BLOCO2:
            return 3;
        case BLOCO3:
            return 4;
        case DEFCONST:
            return 5;
        case CONSTANTE:
            return 6;
        case DEFTYPE:
            return 7;
        case DEFIDENT:
            return 8;
        case IDENTLIST:
            return 9;
        case SEQIDENT:
            return 10;
        case DEFSUBPROGRAMA:
            return 11;
        case DEFPROC:
            return 12;
        case DEFFUNC:
            return 13;
        case AUXSUBPROGRAMA:
            return 14;
        case PARAM:
            return 15;
        case PARAMLIST:
            return 16;
        case DEFPARAM:
            return 17;
        case TIPO:
            return 18;
        case LISTACOMANDOS:
            return 19;
        case SEQCOMANDOS:
            return 20;
        case COMANDO:
            return 21;
        case ATRIBPROC:
            return 22;
        case PARAMETRO:
            return 23;
        case LISTAPAR:
            return 24;
        case CLAUSULAELSE:
            return 25;
    }
    return -1;
}

/**
 * Função chamada no metodo main para fazer a analise sintatica
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void aSintatico()
{
    // declaracoes
    tipoPilhaASP p;
    tipoPilhaASPO q;

    // inicializacao da pilha do analisador sintatico preditivo
    criaPilhaASP(&p);

    // inicializacao da pilha do analisador sintatico com precedencia de operadores
    criaPilhaASPO(&q);

    // utar analise sintatica
    executarASintatica(&p, &q);

    //exibe a lista de erros
    if (!vazia(e))
        imprimirErro(e);
}

/**
 * Função usada para gerar um tipoASP
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
tipoASP retornarTipoASP(int classe)
{
    tipoASP x;
    x.simboloGram = classe;
    return x;

}

/**
 * Função usada para gerar um tipoASPO
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
tipoASPO retornarTipoASPO(int simboloGram, tipoToken token, char tipo)
{
    tipoASPO x;
    x.tipo = tipo;
    if (tipo == 'T' || tipo == '$') {
        x.SG.t = token;
    } else {
        x.SG.nt = simboloGram;
    }
    return x;
}

/**
 * Função usada para retornar se o simbolo da gramatica é um terminal
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int isTerminal(int classe)
{
    return classe <= FINALARQ;
}


/**
 * Função usada para retornar se a analise sintatica acabou
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int finalASintatica(int simboloGram, int classe)
{
    return (simboloGram == classe && classe == FINALARQ);
}

/**
 * Função usada para fazer a analise sintatica
 *
 * @since 22/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void executarASintatica(tipoPilhaASP *p, tipoPilhaASPO *q)
{
    // declaracoes
    tipoToken x;
    int acao = 0;
    int linha = 0;
    FILE *arqC3E;
    tipoPilha pLabel;
    tipoPilha pNomes;
    tipoPilha pParametros;

    // inicializacao das pilhas de geracao de codigo
    criaPilha(&pLabel);
    criaPilha(&pNomes);
    criaPilha(&pParametros);

    // insercao dos atributos iniciais na pilha preditiva
    empilhaASP(retornarTipoASP(FINALARQ), p);
    empilhaASP(retornarTipoASP(PROGRAMA), p);
    x = proximoToken();

    //criacao do arquivo de 3 endereços
    arqC3E = criaArquivo(strcat(x.nomeArq, ".c3e"));

    //verificacao se chegou no final da analise
    while (!finalASintatica(p->topo->item.simboloGram, x.classe)) {
        if (x.linha != linha) {
            linha = x.linha;
            contLinhasCompiladas++;
        }

        printf
            ("pilha: %d -------- token: %d --------- lexema: %s\n",
             p->topo->item.simboloGram, x.classe, x.lexema);
        //verificacao se o simbolo da pilha é um terminal
        if (!isTerminal(p->topo->item.simboloGram)) {
            //verificacao se o simbolo da pilha é um terminal
            if (p->topo->item.simboloGram == EXPRESSAO) {

                // insercao dos atributos iniciais na pilha com precedencia de operadores
                tipoToken t;
                t.classe = FINALCADEIA;
                empilhaASPO(retornarTipoASPO
                        (FINALCADEIA, t, '$'), q);

                //chamada do analisador sintatico de precedencia de operadores
                executarAPO(q, &x, &linha, arqC3E);
                contTemp = 1;
                // acao de desempilhar
                acao = 29;
            } else {
                if (p->topo->item.simboloGram >= ACAOINIT) {
                    geraCodigo(arqC3E,
                            p->topo->
                            item.simboloGram,
                            &pLabel, &pNomes,
                            &pParametros,
                            q->topo->item.lexema);
                    acao = 29;
                } else {
                    // busca da acao a ser executada
                    acao =
                        matrizAcao
                        [retornarLinhaMatrizAcao
                        (p->topo->item.simboloGram)]
                            [retornarColunaMatrizAcao
                            (x.classe)];
                }
                printf("executando acao: %d\n", acao);
            }
            switch (acao) {
                // acao para <PROGRAMA>
                case 1:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (ACAOHALT), p);
                        empilhaASP(retornarTipoASP(PONTO),
                                p);
                        empilhaASP(retornarTipoASP(BLOCO),
                                p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        empilhaASP(retornarTipoASP
                                (ACAOINIT), p);
                        empilhaASP(retornarTipoASP(ID), p);
                        empilhaASP(retornarTipoASP
                                (PROGRAM), p);
                        break;
                    }
                    // acao para <BLOCO>
                case 2:
                    {
                        desempilhaASP(p);
                        if (x.classe == CONST) {
                            empilhaASP(retornarTipoASP
                                    (BLOCO1), p);
                            empilhaASP(retornarTipoASP
                                    (DEFCONST), p);
                            empilhaASP(retornarTipoASP
                                    (CONST), p);
                        } else {
                            empilhaASP(retornarTipoASP
                                    (BLOCO1), p);
                        }
                        break;
                    }
                    // acao para <BLOCO1>
                case 3:
                    {
                        desempilhaASP(p);
                        if (x.classe == TYPE) {
                            empilhaASP(retornarTipoASP
                                    (BLOCO2), p);
                            empilhaASP(retornarTipoASP
                                    (DEFTYPE), p);
                            empilhaASP(retornarTipoASP
                                    (TYPE), p);
                        } else {
                            empilhaASP(retornarTipoASP
                                    (BLOCO2), p);
                        }
                        break;
                    }
                    // acao para <BLOCO2>
                case 4:
                    {
                        desempilhaASP(p);
                        if (x.classe == VAR) {
                            empilhaASP(retornarTipoASP
                                    (BLOCO3), p);
                            empilhaASP(retornarTipoASP
                                    (DEFSUBPROGRAMA),
                                    p);
                            empilhaASP(retornarTipoASP
                                    (DEFIDENT), p);
                            empilhaASP(retornarTipoASP
                                    (VAR), p);
                        } else {
                            empilhaASP(retornarTipoASP
                                    (BLOCO3), p);
                        }
                        break;
                    }
                    // acao para <BLOCO3>
                case 5:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP(END),
                                p);
                        empilhaASP(retornarTipoASP
                                (LISTACOMANDOS), p);
                        empilhaASP(retornarTipoASP
                                (ACAOBLOCO), p);
                        empilhaASP(retornarTipoASP(BEGIN),
                                p);
                        break;
                    }
                    // acao para <DEFCONST>
                case 6:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (DEFCONST), p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        empilhaASP(retornarTipoASP
                                (CONSTANTE), p);
                        empilhaASP(retornarTipoASP(RELOP),
                                p);
                        empilhaASP(retornarTipoASP(ID), p);
                        break;
                    }
                    // acao para <CONSTANTE>
                case 7:
                    {
                        desempilhaASP(p);
                        if (x.classe == LITERAL)
                            empilhaASP(retornarTipoASP
                                    (LITERAL), p);
                        else
                            empilhaASP(retornarTipoASP
                                    (NUM), p);
                        break;
                    }
                    // acao para <DEFTYPE>
                case 8:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (DEFTYPE), p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        empilhaASP(retornarTipoASP(ID), p);
                        empilhaASP(retornarTipoASP(RELOP),
                                p);
                        empilhaASP(retornarTipoASP(TIPO),
                                p);
                        break;
                    }
                    // acao para <DEFIDENT>
                case 9:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (DEFIDENT), p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        empilhaASP(retornarTipoASP
                                (IDENTLIST), p);
                        empilhaASP(retornarTipoASP
                                (DOISPONTOS), p);
                        empilhaASP(retornarTipoASP(TIPO),
                                p);
                        break;
                    }
                    // acao para <IDENTLIST>
                case 10:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (SEQIDENT), p);
                        empilhaASP(retornarTipoASP(ID), p);
                        break;
                    }
                    // acao para <SEQIDENT>
                case 11:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (SEQIDENT), p);
                        empilhaASP(retornarTipoASP(ID), p);
                        empilhaASP(retornarTipoASP
                                (VIRGULA), p);
                        break;
                    }
                    // acao para <DEFSUBPROGRAMA>
                case 12:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (DEFSUBPROGRAMA), p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        if (x.classe == PROCEDURE)
                            empilhaASP(retornarTipoASP
                                    (DEFPROC), p);
                        else
                            empilhaASP(retornarTipoASP
                                    (DEFFUNC), p);
                        break;
                    }
                    // acao para <DEFPROC>
                case 13:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (ACAORETORNOPROCEDURE),
                                p);
                        empilhaASP(retornarTipoASP(BLOCO),
                                p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        empilhaASP(retornarTipoASP
                                (AUXSUBPROGRAMA), p);
                        empilhaASP(retornarTipoASP(ID), p);
                        empilhaASP(retornarTipoASP
                                (ACAONOMSUBPROGRAMA),
                                p);
                        empilhaASP(retornarTipoASP
                                (PROCEDURE), p);
                        break;
                    }
                    // acao para <DEFFUNC>
                case 14:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (ACAORETORNOFUNCAO), p);
                        empilhaASP(retornarTipoASP(BLOCO),
                                p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        empilhaASP(retornarTipoASP(TIPO),
                                p);
                        empilhaASP(retornarTipoASP
                                (DOISPONTOS), p);
                        empilhaASP(retornarTipoASP
                                (AUXSUBPROGRAMA), p);
                        empilhaASP(retornarTipoASP(ID), p);
                        empilhaASP(retornarTipoASP
                                (ACAONOMSUBPROGRAMA),
                                p);
                        empilhaASP(retornarTipoASP
                                (FUNCTION), p);
                        break;
                    }
                    // acao para <AUXSUBPROGRAMA>
                case 15:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (ACAOGETPAR), p);
                        empilhaASP(retornarTipoASP
                                (FECHAPAR), p);
                        empilhaASP(retornarTipoASP
                                (ACAONAOPARAMETROS), p);
                        empilhaASP(retornarTipoASP(PARAM),
                                p);
                        empilhaASP(retornarTipoASP
                                (ACAOPARAMETROSFUNCOES),
                                p);
                        empilhaASP(retornarTipoASP
                                (ABREPAR), p);
                        break;
                    }
                    // acao para <PARAM>
                case 16:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (PARAMLIST), p);
                        empilhaASP(retornarTipoASP
                                (DEFPARAM), p);
                        break;
                    }
                    // acao para <PARAMLIST>
                case 17:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (PARAMLIST), p);
                        empilhaASP(retornarTipoASP
                                (DEFPARAM), p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        break;
                    }
                    // acao para <DEFPARAM>
                case 18:
                    {
                        desempilhaASP(p);
                        if (x.classe == VAR) {
                            empilhaASP(retornarTipoASP
                                    (IDENTLIST), p);
                            empilhaASP(retornarTipoASP
                                    (DOISPONTOS),
                                    p);
                            empilhaASP(retornarTipoASP
                                    (TIPO), p);
                            empilhaASP(retornarTipoASP
                                    (VAR), p);
                        } else {
                            empilhaASP(retornarTipoASP
                                    (IDENTLIST), p);
                            empilhaASP(retornarTipoASP
                                    (DOISPONTOS),
                                    p);
                            empilhaASP(retornarTipoASP
                                    (TIPO), p);
                        }
                        break;
                    }
                    // acao para <TYPE>
                case 19:
                    {
                        desempilhaASP(p);
                        switch (x.classe) {
                            case INTEGER:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (INTEGER), p);
                                    break;
                                }
                            case REAL:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (REAL), p);
                                    break;
                                }
                            case CHAR:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (CHAR), p);
                                    break;
                                }
                            case BOOLEAN:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (BOOLEAN), p);
                                    break;
                                }
                            case CADEIA:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (CADEIA), p);
                                    break;
                                }
                        }
                        break;
                    }
                    // acao para <LISTACOMANDOS>
                case 20:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (SEQCOMANDOS), p);
                        empilhaASP(retornarTipoASP
                                (COMANDO), p);
                        break;
                    }
                    // acao para <SEQCOMANDOS>
                case 21:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (SEQCOMANDOS), p);
                        empilhaASP(retornarTipoASP
                                (COMANDO), p);
                        empilhaASP(retornarTipoASP
                                (PONTOVIRGULA), p);
                        break;
                    }
                    // acao para <COMANDO>
                case 22:
                    {
                        desempilhaASP(p);
                        switch (x.classe) {
                            case ID:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOATRIBUICAO3),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ATRIBPROC),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ID), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOATRIBUICAO1),
                                         p);
                                    break;
                                }
                            case BEGIN:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (END), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (LISTACOMANDOS),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (BEGIN), p);
                                    break;
                                }
                            case IF:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOELSE1),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (CLAUSULAELSE),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOIF2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (COMANDO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOIF1),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (THEN), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (EXPRESSAO),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (IF), p);
                                    break;
                                }
                            case REPEAT:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOREPEAT2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (EXPRESSAO),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (UNTIL), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (LISTACOMANDOS),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOREPEAT1),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (REPEAT), p);
                                    break;
                                }
                            case WHILE:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOWHILE3),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (COMANDO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (DO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOWHILE2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (EXPRESSAO),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOWHILE1),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (WHILE), p);
                                    break;
                                }
                            case FOR:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOFOR4),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (COMANDO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (DO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOFOR3),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (EXPRESSAO),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (TO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOFOR2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (EXPRESSAO),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ATRIB), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ID), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOFOR1),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (FOR), p);
                                    break;
                                }
                            case READ:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (COMANDO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOREAD2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ATRIBPROC),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (READ), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOREAD1),
                                         p);
                                    break;
                                }
                            case READLN:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (COMANDO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOREADLN2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ATRIBPROC),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (READLN), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOREADLN1),
                                         p);
                                    break;
                                }
                            case WRITE:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (COMANDO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOWRITE2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ATRIBPROC),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (WRITE), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOWRITE1),
                                         p);
                                    break;
                                }
                            case WRITELN:
                                {
                                    empilhaASP
                                        (retornarTipoASP
                                         (COMANDO), p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOWRITELN2),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ATRIBPROC),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (ACAOCOMANDOWRITELN1),
                                         p);
                                    empilhaASP
                                        (retornarTipoASP
                                         (WRITELN), p);
                                    break;
                                }
                        }
                        break;
                    }
                    // acao para <ATRIBPROC>
                case 23:
                    {
                        desempilhaASP(p);
                        if (x.classe == ATRIB) {
                            empilhaASP(retornarTipoASP
                                    (ACAOATRIBUICAO2),
                                    p);
                            empilhaASP(retornarTipoASP
                                    (EXPRESSAO), p);
                            empilhaASP(retornarTipoASP
                                    (ATRIB), p);
                        } else {
                            empilhaASP(retornarTipoASP
                                    (PARAMETRO), p);
                        }
                        break;
                    }
                    // acao para <PARAMETRO>
                case 24:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (ACAOPUTPAR), p);
                        empilhaASP(retornarTipoASP
                                (LISTAPAR), p);
                        empilhaASP(retornarTipoASP
                                (ACAOPARAMETRO1), p);
                        empilhaASP(retornarTipoASP
                                (EXPRESSAO), p);
                        break;
                    }
                    // acao para <LISTAPAR>
                case 25:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (LISTAPAR), p);
                        empilhaASP(retornarTipoASP
                                (ACAOPARAMETRO1), p);
                        empilhaASP(retornarTipoASP
                                (EXPRESSAO), p);
                        empilhaASP(retornarTipoASP
                                (VIRGULA), p);
                        break;
                    }
                    // acao para <CALSULAELSE>
                case 26:
                    {
                        desempilhaASP(p);
                        empilhaASP(retornarTipoASP
                                (COMANDO), p);
                        empilhaASP(retornarTipoASP(ELSE),
                                p);
                        break;
                    }
                    // acao para <EPSOLON>
                case 29:
                    {
                        desempilhaASP(p);
                        break;
                    }
                    // acao erro ocorrido
                case -1:
                    {
                        //insercao do erro e chamada do metodo do panico
                        inserirErro(retornaErro
                                (p->topo->
                                 item.simboloGram, x),
                                &e);
                        panico(p, &x, &linha);
                        break;
                    }
                    //erro ocorrido com seguintes
                case 0:
                    {
                        //insercao do erro e chamada do metodo do panico
                        inserirErro(retornaErro
                                (p->topo->
                                 item.simboloGram, x),
                                &e);
                        panico(p, &x, &linha);
                        break;
                    }

            }
        } else {
            // verificacao se o token foi achado
            if (p->topo->item.simboloGram == x.classe) {

                if (x.classe == ID) {
                    if (validaListaPar > 0) {
                        empilha(retornarTipoNome
                                (x.lexema),
                                &pParametros);
                    } else if (validaListaPar < 0) {
                        validaListaPar = 0;
                        empilha(retornarTipoNome
                                (x.lexema),
                                &pNomes);
                    }
                }
                desempilhaASP(p);
                x = proximoToken();
            }
            // erro
            else {
                //insercao do erro e chamada do metodo do panico
                inserirErro(retornaErro
                        (p->topo->item.simboloGram, x),
                        &e);
                panico(p, &x, &linha);
            }
        }
    }
    // Fecha o arquivo
    if (!fechaArquivo(arqC3E)) {
        printf("ERROR ao fechar o arquivo");
    }
}

/**
 * Função usada para fazer o tratamento de erro e continuar a analise
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void panico(tipoPilhaASP *p, tipoToken *x, int *linha)
{
    int linLocal = *(linha);
    printf("erro panico\n");
    if (isTerminal(p->topo->item.simboloGram) && p->topo != p->fundo
            && p->topo->item.simboloGram != FINALARQ) {
        *(x) = proximoToken();
        desempilhaASP(p);
    } else {
        while (!verificarSincronismo
                (p->topo->item.simboloGram, x->classe)
                && x->classe != FINALARQ) {
            *(x) = proximoToken();
            if (x->linha != linLocal) {
                linLocal = x->linha;
                contLinhasCompiladas++;
            }
        }
        if ((matrizAcao
                    [retornarLinhaMatrizAcao(p->topo->item.simboloGram)]
                    [retornarColunaMatrizAcao(x->classe)] == 0
                    ||
                    matrizAcao[retornarLinhaMatrizAcao
                    (p->topo->item.simboloGram)]
                    [retornarColunaMatrizAcao(x->classe)]
                    == 29) && p->topo != p->fundo
                && p->topo->item.simboloGram != FINALARQ)
            desempilhaASP(p);
        if (x->classe != FINALARQ
                && p->topo->item.simboloGram == FINALARQ)
            *(x) = proximoToken();
        if (x->classe == FINALARQ
                && p->topo->item.simboloGram != FINALARQ)
            desempilhaASP(p);
    }
    if (x->linha != linLocal) {
        linLocal = x->linha;
        contLinhasCompiladas++;
    }
    *(linha) = linLocal;

}

/**
 * Função usada para verificar se o TOKEN é simbolo de sincronismo
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int verificarSincronismo(int simboloGram, int classe)
{
    return matrizAcao[retornarLinhaMatrizAcao(simboloGram)]
        [retornarColunaMatrizAcao(classe)] >= 0;
}

/**
 * Função usada para verificar qual foi o erro ocorrido na analise Preditiva e retornar o seu erro
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
tErro retornaErro(int simboloGram, tipoToken x)
{
    tErro e;
    e.linha = x.linha;
    if (!isTerminal(simboloGram)) {
        switch (simboloGram) {
            case PROGRAMA:
                {
                    e.codErro = -7;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave PROGRAM e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case BLOCO:
                {
                    e.codErro = -8;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave CONST ou TYPE ou VAR ou BEGIN e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case BLOCO1:
                {
                    e.codErro = -9;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave TYPE ou VAR ou BEGIN e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case BLOCO2:
                {
                    e.codErro = -10;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave VAR ou BEGIN e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case BLOCO3:
                {
                    e.codErro = -11;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave BEGIN e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case DEFCONST:
                {
                    e.codErro = -12;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um IDENTIFICADOR e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case CONSTANTE:
                {
                    e.codErro = -13;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um NUM ou um LITERAL e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case DEFTYPE:
                {
                    e.codErro = -14;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado palavra chave INTEGER ou REAL ou CHAR ou BOOLEAN ou CADEIA e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case DEFIDENT:
                {
                    e.codErro = -15;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado palavra chave INTEGER ou REAL ou CHAR ou BOOLEAN ou CADEIA e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case IDENTLIST:
                {
                    e.codErro = -16;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um IDENTIFICADOR e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case SEQIDENT:
                {
                    e.codErro = -17;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado uma VIRGULA e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case DEFSUBPROGRAMA:
                {
                    e.codErro = -18;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave FUNCTION ou PROCEDURE foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case DEFPROC:
                {
                    e.codErro = -19;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave PROCEDURE foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case DEFFUNC:
                {
                    e.codErro = -20;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave FUNCTION foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case AUXSUBPROGRAMA:
                {
                    e.codErro = -21;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um '(' foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case PARAM:
                {
                    e.codErro = -22;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave VAR ou um TIPO definido na linguagem e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case PARAMLIST:
                {
                    e.codErro = -23;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um PONTO E VIRGULA e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case DEFPARAM:
                {
                    e.codErro = -24;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado a palavra chave VAR ou um TIPO definido na linguagem e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case TIPO:
                {
                    e.codErro = -25;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado palavra chave INTEGER ou REAL ou CHAR ou BOOLEAN ou CADEIA e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case LISTACOMANDOS:
                {
                    e.codErro = -26;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um IDENTIFICADOR ou uma palavra chave de comando como WHILE, IF ou FOR e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case SEQCOMANDOS:
                {
                    e.codErro = -27;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um PONTO E VIRGULA e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case COMANDO:
                {
                    e.codErro = -28;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um IDENTIFICADOR ou uma palavra chave de comando como WHILE, IF ou FOR e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case ATRIBPROC:
                {
                    e.codErro = -29;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um comando de atribuiçao e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case PARAMETRO:
                {
                    e.codErro = -29;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um IDENTIFICADOR ou NOT ou NUM ou LITERAL e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case LISTAPAR:
                {
                    e.codErro = -31;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado um PONTO E VIRGULA e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
            case CLAUSULAELSE:
                {
                    e.codErro = -32;
                    strcpy(e.mensagem,
                            "Erro Sintático: Era esperado o comando ELSE e foi recebido o Token: ");
                    strcat(e.mensagem,
                            converteMaiusculo(x.lexema));
                    break;
                }
        }
    } else {
        e.codErro = -33;
        strcpy(e.mensagem,
                "Erro Sintático: Token inválido encontrado!!! Era esperado o Token: ");
        strcat(e.mensagem, converteMaiusculo(x.lexema));
    }
    contErroSintatico++;
    return e;
}

/**
 * Função usada para fazer a analise sintatica com precedencia de operadores
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void executarAPO(tipoPilhaASPO *q, tipoToken *x, int *linha, FILE *arqC3E)
{
    // declaracoes
    int precedencia;
    int verifica = FINALCADEIA;
    int linLocal = *(linha);
    char tipo = '$';
    int pilhaVazia = 0;
    apontASPO p;
    tipoPilha pTemp;

    // inicializacao das pilhas de geracao de codigo
    criaPilha(&pTemp);

    // retornando o ultimo terminal da pilha
    p = retornarUltimoTerminal(q);
    while (!finalASPO(tipo, verifica, x->classe)) {
        printf("\n-------------\nlexema: %s\n", x->lexema);
        // verificando qual precedencia do terminal
        precedencia =
            matrizPO[retornarLinhaColunaMatrizPO
            (p->item.SG.
             t.classe)][retornarLinhaColunaMatrizPO
            (x->classe)];
        //inserindo o token na pilha
        if (precedencia == PRECEDENCIAMENOR
                || precedencia == PRECEDENCIAIGUAL) {
            printf("empilha.... %d\n", x->classe);
            empilhaASPO(retornarTipoASPO(x->classe, *x, 'T'),
                    q);
            *(x) = proximoToken();
        }
        //executando a reducao
        else if (precedencia == PRECEDENCIAMAIOR) {
            printf("reduzindo.... %d\n", p->item.SG.t.classe);
            executarReducao(arqC3E, q, x, &pTemp);
        }
        // erro de precedencia
        else {
            inserirErro(complementaFrase
                    (precedencia, q, x, &pTemp, arqC3E),
                    &e);
        }
        // retornando o ultimo terminal da pilha
        p = retornarUltimoTerminal(q);
        // geracao do atributos de verificacao de final de analise
        tipo = p->item.tipo;
        if (q->topo->item.tipo == 'N')
            verifica = q->topo->item.SG.nt;
        else
            verifica = q->topo->item.SG.t.classe;
        //contagem de linhas compiladas
        if (x->linha != linLocal) {
            linLocal = x->linha;
            contLinhasCompiladas++;
        }
        pilhaVazia = 1;
    }
    if (!pilhaVazia)
        inserirErro(complementaFrase(-4, q, x, &pTemp, arqC3E),
                &e);
    *(linha) = linLocal;
}

/**
 * Função usada para verifica se a analise sintatica de precedencia de operadores
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int finalASPO(char tipo, int simboloGram, int classe)
{
    return (tipo == '$' && simboloGram == EXPRESSAO
            && !verificaExistenciaToken(classe));
}

/**
 * Função usada para retorna a linha e a coluna da matrizPO
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int retornarLinhaColunaMatrizPO(int classe)
{
    switch (classe) {
        case ADDOP:
            return 0;
        case MULTOP:
            return 1;
        case ABREPAR:
            return 2;
        case FECHAPAR:
            return 3;
        case ID:
            return 4;
        case NUM:
            return 5;
        case LITERAL:
            return 6;
        case NOT:
            return 7;
        case VIRGULA:
            return 8;
        case RELOP:
            return 9;
        case FINALCADEIA:
            return 10;
        case EXPRESSAO:
            return 11;
    }
    return 10;
}

/**
 * Função para verificar a existencia do Token na expressao
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int verificaExistenciaToken(int classe)
{
    return (classe == ADDOP || classe == MULTOP || classe == ABREPAR
            || classe == FECHAPAR || classe == ID || classe == NUM
            || classe == LITERAL || classe == NOT || classe == VIRGULA
            || classe == RELOP || classe == EXPRESSAO);
}

/**
 * Função para gerar estatisticas do compilador
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void gerarEstatistica()
{
    printf("\n\nESTATISTICA:\n");
    printf("Quantidade de erros Léxicos: %d\n", contErroLexico);
    printf("Quantidade de erros Sintáticos: %d\n", contErroSintatico);
    printf("Quantidade de linhas Compiladas: %d\n",
            contLinhasCompiladas);
}

/**
 * Função para fazer o tratamento de erro por complemento de frase
 *
 * @since 23/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
tErro complementaFrase(int codigo, tipoPilhaASPO *q, tipoToken *x,
        tipoPilha *pTemp, FILE *arqC3E)
{
    //declaracoes
    tErro e;
    tipoToken y;
    apontASPO p;
    e.linha = x->linha;
    printf("ERRO...  %d\n", codigo);
    //verificacao do erro ocorrido
    switch (codigo) {
        case -1:
            {
                desempilhaASPO(q);
                p = retornarUltimoTerminal(q);
                y.classe = FINALCADEIA;
                empilhaASPO(retornarTipoASPO(EXPRESSAO, y, 'N'),
                        q);
                while (p->item.SG.t.classe == ADDOP
                        || p->item.SG.t.classe == MULTOP) {
                    executarReducao(arqC3E, q, x, pTemp);
                    p = retornarUltimoTerminal(q);
                }
                y.classe = ADDOP;
                empilhaASPO(retornarTipoASPO(1, y, 'T'), q);
                e.codErro = -34;
                strcpy(e.mensagem,
                        "Ausência de Operador Binario");
                break;
            }
        case -2:
            {
                e.codErro = -35;
                y.classe = FECHAPAR;
                empilhaASPO(retornarTipoASPO(1, y, 'T'), q);
                strcpy(e.mensagem, "Parentese a direita ausente");
                break;
            }
        case -3:
            {
                desempilhaASPO(q);
                y.classe = ABREPAR;
                empilhaASPO(retornarTipoASPO(1, y, 'T'), q);
                y.classe = FINALCADEIA;
                empilhaASPO(retornarTipoASPO(EXPRESSAO, y, 'N'),
                        q);
                e.codErro = -36;
                strcpy(e.mensagem,
                        "Parentese a direita nao balanceado");
                break;
            }
        case -4:
            {
                y.classe = FINALCADEIA;
                empilhaASPO(retornarTipoASPO(EXPRESSAO, y, 'N'),
                        q);
                e.codErro = -37;
                strcpy(e.mensagem, "Operando Ausente");
                break;
            }
        case -5:
            {
                e.codErro = -38;
                desempilhaASPO(q);
                strcpy(e.mensagem,
                        "Erro Sintático: Token invalido na expressao!");
                break;
            }
        case -6:
            {
                desempilhaASPO(q);
                y.classe = FINALCADEIA;
                empilhaASPO(retornarTipoASPO(EXPRESSAO, y, 'N'),
                        q);
                y.classe = FECHAPAR;
                empilhaASPO(retornarTipoASPO(1, y, 'T'), q);
                e.codErro = -36;
                strcpy(e.mensagem,
                        "Ausencia de Expressao entre os parenteses");
                break;
            }
    }
    //contador de erros sintaticos
    contErroSintatico++;
    return e;
}


/**
 * Função usada para fazer a reducao Button-UP
 *
 * @since 24/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void executarReducao(FILE *arqC3E, tipoPilhaASPO *q, tipoToken *x,
        tipoPilha *pTemp)
{
    //declaracoes
    apontASPO p = q->topo, k;
    int precedencia = 0;
    int achou = 0;
    int valorRemover = 0;
    int codigoErro = 0;
    int contItensRemover = 0, i;
    char strValor[20], buffer[20];
    tipoToken t;

    char *lexema;
    printf("CHEGUEI AQUI_");

    lexema = (char *) malloc(160 * sizeof(char));
    // encontrando o ultimo terminal da pilha


    p = retornarUltimoTerminal(q);
    k = p;

    // busca do itens possiveis para reducao
    while (!achou) {
        if (k->ant->item.tipo != 'T' && k != q->fundo
                && k->ant->item.tipo != '$')
            k = k->ant;
        valorRemover = p->item.SG.t.classe;
        precedencia =
            matrizPO[retornarLinhaColunaMatrizPO
            (k->ant->item.SG.
             t.classe)][retornarLinhaColunaMatrizPO
            (valorRemover)];
        achou = (precedencia != PRECEDENCIAMAIOR);
        if ((!achou && k != q->fundo)
                || (k->ant->item.SG.t.classe == ABREPAR
                    && p->item.SG.t.classe == FECHAPAR))
            k = k->ant;
    }

    // geracao do item a ser comparado para vierificar a reducao
    p = q->fundo->prox;
    while (p != k)
        p = p->prox;
    sprintf(buffer, "%d", p->item.SG.t.classe);
    strcpy(strValor, buffer);
    strcpy(lexema, p->item.SG.t.lexema);
    p = p->prox;
    contItensRemover++;
    while (p != q->topo->prox) {
        if (p->item.tipo == 'T' || p->item.tipo == '$') {
            sprintf(buffer, "%d", p->item.SG.t.classe);
            strcpy(lexema, p->item.SG.t.lexema);
        } else
            sprintf(buffer, "%d", p->item.SG.nt);
        strcat(strValor, buffer);
        p = p->prox;
        contItensRemover++;
    }

    // verificação se a reducao é possivel
    printf("CHEGUEI AQUI");

    if (possivelReducao(strValor, pTemp, lexema, arqC3E)) {
        for (i = 0; i < contItensRemover; i++)
            desempilhaASPO(q);
        t.classe = FINALCADEIA;
        empilhaASPO(retornarTipoASPO(EXPRESSAO, t, 'N'), q);
        strcpy(q->topo->item.lexema, pTemp->topo->item.lexema);
    }
    // erro de reducao
    else {

        // geracao do codigo do erro ocorrido
        codigoErro = testarErro(valorRemover);
        inserirErro(complementaFrase
                (codigoErro, q, x, pTemp, arqC3E), &e);
    }
}


/**
 * Função usada para verificar se a reducao é possivel
 *
 * @since 24/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int possivelReducao(char strValor[20], tipoPilha *pTemp, char lexema[160],
        FILE *arqC3E)
{
    //EXPRESSAO - RELOP - EXPRESSAO
    if (!strcmp(strValor, "985598")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL(pTemp->topo->ant->ant->item.lexema)
            SINAL2(lexema)
            VARIAVEL2(pTemp->topo->ant->item.lexema) return 1;
    }
    //EXPRESSAO - ADDOP - EXPRESSAO
    else if (!strcmp(strValor, "985398")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL(pTemp->topo->ant->ant->item.lexema)
            SINAL2(lexema)
            VARIAVEL2(pTemp->topo->ant->item.lexema) return 1;
    }
    //EXPRESSAO - MULTOP - EXPRESSAO
    else if (!strcmp(strValor, "985498")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL(pTemp->topo->ant->ant->item.lexema)
            SINAL2(lexema)
            VARIAVEL2(pTemp->topo->ant->item.lexema) return 1;
    }
    //NOT - EXPRESSAO
    else if (!strcmp(strValor, "2398")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL(lexema)
            SINAL(' ')
            VARIAVEL2(pTemp->topo->ant->item.lexema) return 1;
    }
    //ID
    else if (!strcmp(strValor, "50")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL2(lexema) return 1;
    }
    //NUM
    else if (!strcmp(strValor, "51")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL2(lexema) return 1;
    }
    //LITERAL
    else if (!strcmp(strValor, "52")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL2(lexema) return 1;
    }
    //ABREPAR - EXPRESSAO - FECHAPAR
    else if (!strcmp(strValor, "569857")) {
        return 1;
    }
    //EXPRESSAO - VIRGULA - EXPRESSAO (FUNCAO PARAMETROS)
    else if (!strcmp(strValor, "985998")) {
        if (contPutpar) {
            PUTPAR(pTemp->topo->ant->item.lexema)
                PUTPAR(pTemp->topo->item.lexema)
                contPutpar = 0;
        } else
            PUTPAR(pTemp->topo->item.lexema)
                return 1;
    }
    //ID - EXPRESSAO (FUNCAO)
    else if (!strcmp(strValor, "5098")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB CALL VARIAVEL2(lexema) contPutpar = 1;
        return 1;
    }
    //FALSE
    else if (!strcmp(strValor, "27")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL2("0") return 1;
    }
    //TRUE
    else if (!strcmp(strValor, "26")) {
        empilha(retornarTipoNome(geraTemp()), pTemp);
        VARIAVEL(pTemp->topo->item.lexema);
        ATRB VARIAVEL2("1") return 1;
    }
    return 0;
}


/**
 * Função usada para verificar qual erro ocorreu
 *
 * @since 24/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int testarErro(int classe)
{
    switch (classe) {
        case ADDOP:
            return -4;
        case RELOP:
            return -4;
        case MULTOP:
            return -4;
        case NOT:
            return -1;
        case ID:
            return -1;
        case NUM:
            return -1;
        case LITERAL:
            return -1;
        case ABREPAR:
            return -2;
        case FECHAPAR:
            return -6;
        case VIRGULA:
            return -4;
    }
    return -5;
}


/**
 * Função usada para apontar para o ultimo terminal da pilhaASPO
 *
 * @since 24/10/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
apontASPO retornarUltimoTerminal(tipoPilhaASPO *q)
{
    apontASPO p = q->topo;
    while (p->item.tipo == 'N') {
        p = p->ant;
    }
    return p;
}
