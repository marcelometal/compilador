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

#ifndef scannerH
#define scannerH

// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arquivo.h"
#include "constantes.h"
#include "tratadorErro.c"
#include "palavraChave.c"


// estrutura do token
typedef struct ttoken
{
    int classe;
    char lexema[160];
    char nomeArq[15];
    int linha;
    int coluna;
} tipoToken;

// estrutura para lista encadeada de Token
typedef struct nodo *apont;
typedef struct nodo
{
    tipoToken item;
    apont prox;
} celula;
typedef struct lista
{
    apont primeiro,ultimo;
} tipoLista;

// Estrurura do Buffer
typedef struct buf
{
    char valor[MAXBUFFER];
    int inicio;
    int posicao;
} buffer;

//prototipos
void criaLista(tipoLista *l);
void insereToken(tipoToken x, tipoLista *l);
int vaziaLista(tipoLista l);
void iniciaBuffer(buffer *x);
void alexico(char arquivo[15]);
void lerLinhaFonte(buffer *vetBuffer, int qtdeCaracteres, FILE *arq);
void retroceder(buffer *vetBuffer);
char lerProxCaractere(buffer *vetBuffer);
char verificarAvancarCaractere(FILE *arq, buffer *vetBuffer, char c);
int retornaColuna(char caractere,int estado);
void  avancarToken(buffer *vetBuffer);
tipoToken retornarToken(char arquivo[15],buffer *vetbuffer,int classe);
char *substring(buffer *b);
void eliminaEspacos(buffer *vetBuffer);
int finalBuffer(buffer *b);
void eliminaEspacosFinal(buffer *vetBuffer);
void  avancarCaractere(buffer *vetBuffer);
void verificarErro(listaErro *e, int estado,buffer *b);
int retornaLiteral(FILE *arq, buffer *b, char *lexema);
int eliminarComentario(FILE *arq, buffer *b);
char *converteMaiusculo(char lexema[160]);
void imprimeListaToken(tipoLista lista);
void retornarListaToken(tipoLista *l, listaErro *e, char arquivo[15]);
tipoToken proximoToken();

#endif
