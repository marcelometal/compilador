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

#ifndef definicoesC3EH
#define definicoesC3EH

//bibliotecas
#include <stdio.h>
#include <stdlib.h>


// definicoes do codigo de 3 endereços
#define VARIAVEL(var) fprintf(arqC3E,"%s",var);
#define VARIAVEL2(var) fprintf(arqC3E,"%s\n",var);
#define NOMFUNCAO(var) fprintf(arqC3E,"%s\n",var);
#define SINAL(var) fprintf(arqC3E,"%c",var);
#define SINAL2(var) fprintf(arqC3E,"%s",var);
#define LABEL(nome) fprintf(arqC3E,"%s:\n",nome);
#define ATRB fprintf(arqC3E,":=");
#define DESVIO(label) fprintf(arqC3E,"goto %s\n",label);
#define COMPARACAO(expressao) fprintf(arqC3E,"if %s = 0 ",expressao);
#define COMPARACAO2(expressao1,sinal,expressao2) fprintf(arqC3E,"if %s %c %s ",expressao1,sinal,expressao2);
#define CALL fprintf(arqC3E,"call ");
#define PUTPAR(parametro) fprintf(arqC3E,"putpar %s\n",parametro);
#define GETPAR(parametro) fprintf(arqC3E,"getpar %s\n",parametro);
#define RETURN(var) fprintf(arqC3E,"return %s\n",var);
#define IREAD fprintf(arqC3E,"iread\n");
#define FREAD fprintf(arqC3E,"fread\n");
#define CREAD fprintf(arqC3E,"cread\n");
#define IWRITE fprintf(arqC3E,"iwrite\n");
#define FWRITE fprintf(arqC3E,"fwrite\n");
#define CWRITE fprintf(arqC3E,"cwrite\n");
#define HALT fprintf(arqC3E,"halt\n");


//variavel
int veriAtribuicao=0;
int contPutpar=1;
int contTemp=1;
int contLabelIf=1;
int contLabelElse=1;
int contLabelFor=1;
int contLabelWhile=1;
int contLabelRepeat=1;
int validaListaPar=0;
int leituraRead=0;
int leituraReadln=0;
int escritaWrite=0;
int escritaWriteln=0;

// estrutura de todas as pilhas do Codigo de 3 Enderecos
typedef struct pGeral
{
    char lexema[160];
} tipoNome;
typedef struct nodoPilhaGeral *apontGeral;
typedef struct nodoPilhaGeral
{
    tipoNome item;
    apontGeral prox;
    apontGeral ant;
} celulaGeral;
typedef struct pilhaNomesGeral
{
    apontGeral topo,fundo;
} tipoPilha;

//prototipos
void criaPilha(tipoPilha *p);
void empilha(tipoNome x, tipoPilha *p);
void desempilha(tipoPilha *p);
void geraCodigo(FILE *arqC3E,int acao,tipoPilha *pLabel,tipoPilha *pNomes,tipoPilha *pParametros,char lexema[160]);
char *concatena(char buffer[25],int numero);
char *geraTemp();
tipoNome retornarTipoNome(char lexema[160]);
#endif
