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

#ifndef palavraChaveH
#define palavraChaveH

//bibliotecas
#include "constantes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Estrutura da palavra chave
typedef struct pchave
{
    int classe;
    char lexema[160];
} pChave;

// estrutura da lista encadeada de Palavras Chaves
typedef struct cel *apontador;
typedef struct cel
{
    pChave item;
    apontador prox;
} celPc;
typedef struct listaPc
{
    apontador primeiro,ultimo;
} tipoListaPc;

//Prototipos
int pesquisaPc(char lexema[160]);
void inserePc(pChave x, tipoListaPc *l);
void  criaListaPc(tipoListaPc *l);
void inserirPalavraChave();
int hashing(char lexema[160]);
void inicializaPc();
void imprimeLista();

// array com palavras chaves
tipoListaPc listaPc[MAXPC];
#endif
