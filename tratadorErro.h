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

#ifndef tratadorErroH
#define tratadorErroH

//bibliotecas
#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrutura de erro
typedef struct erro
{
    int codErro;
    int linha;
    char mensagem[160];

} tErro;

// estrutura para lista encadeada de Erro
typedef struct cerro *apontErro;
typedef struct cerro
{
    tErro item;
    apontErro prox;
} cErro;

typedef struct list
{
    apontErro primeiro,ultimo;
}listaErro;

//prototipos
void criaListaErro(listaErro *e);
int vazia(listaErro e);
void inserirErro(tErro x,listaErro *e);
void imprimirErro(listaErro e);
tErro recuperarErro(int linha, int codErro,  char *lexema);

#endif

