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

/* Contem metodos para manipulacao de arquivos */

#include <stdio.h>
#include <stdlib.h>

/**
 * Função usada para criar um arquivo no dir. atual
 *
 * @since 18/09/2003
 * @access public
 */
FILE *criaArquivo(char *f)
{
    FILE *temp;
    if ((temp = fopen(f, "w")) == 0) {
        printf("Erro ao criar arquivo\n");
        exit(1);
    }
    return temp;
}


/**
 * Função usada para abrir um arquivo do diretorio atual
 *
 * @since 18/09/2003
 * @access public
 */
FILE *abreArquivo(char *f)
{
    FILE *temp;
    if ((temp = fopen(f, "r")) == 0) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    return temp;
}


/**
 * Função usada para fechar o arquivo
 *
 * @since 18/09/2003
 * @access public
 */
int fechaArquivo(FILE *f)
{
    if (fclose(f) == EOF)
        return 0;
    return 1;
}
