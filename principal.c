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
   Neste arquivo está as funções principais para manipulação
   do compilador
   */
//biblioteca pára analise léxica
#include "parser.c"
/**
 * Método principal
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int main(int argc, char **argv)
{
    int i;
    for (i = 1; i < argc; i++) {
        aLexico(argv[i]);
        aSintatico();
        gerarEstatistica();
        contLinha = 0;
    }
    return 0;
}
