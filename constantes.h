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

#ifndef constantesH
#define constantesH

//-------------------------
// Constantes das Classes
//-------------------------

//Palavras Chaves
#define PROGRAM 1
#define CONST 2
#define TYPE 3
#define VAR 4
#define BEGIN 5
#define END 6
#define PROCEDURE 7
#define FUNCTION 8
#define INTEGER 9
#define REAL 10
#define CHAR 11
#define BOOLEAN 12
#define CADEIA 13
#define IF 14
#define THEN 15
#define ELSE 16
#define WHILE 17
#define DO 18
#define CARACTERE_ESPECIAL 18
#define REPEAT 19
#define UNTIL 20
#define FOR 21
#define TO 22
#define NOT 23
#define WRITE 24
#define WRITELN 25
#define TRUE 26
#define FALSE 27
#define READ 28
#define READLN 29
#define AND 30
#define OR 31

// definiçoes do Compilador
#define ID 50
#define NUM 51
#define LITERAL 52
#define ADDOP 53
#define MULTOP 54
#define RELOP 55
#define ABREPAR 56
#define FECHAPAR 57
#define ATRIB 58
#define VIRGULA 59
#define PONTO 60
#define PONTOVIRGULA 61
#define DOISPONTOS 62
#define FINALARQ 63
#define FINALLISTAPC 64

// Constantes dos nao-terminais
#define PROGRAMA 70
#define BLOCO 71
#define BLOCO1 72
#define BLOCO2 73
#define BLOCO3 74
#define DEFCONST 75
#define CONSTANTE 76
#define DEFTYPE 77
#define DEFIDENT 78
#define IDENTLIST 79
#define SEQIDENT 80
#define DEFSUBPROGRAMA 81
#define DEFPROC 82
#define DEFFUNC 83
#define AUXSUBPROGRAMA 84
#define PARAM 85
#define PARAMLIST 86
#define DEFPARAM 87
#define TIPO 88
#define LISTACOMANDOS 89
#define SEQCOMANDOS 90
#define COMANDO 91
#define ATRIBPROC 92
#define PARAMETRO 93
#define LISTAPAR 94
#define CLAUSULAELSE 95
#define FUNCAO 96
#define ENTREPAR 97
#define EXPRESSAO 98
#define ENTER printf("\n");

//constantes de codigo de 3 enderecos
#define ACAOINIT 101
#define ACAONOMSUBPROGRAMA 102
#define ACAOBLOCO 103
#define ACAOPARAMETROSFUNCOES 104
#define ACAOGETPAR 105
#define ACAORETORNOPROCEDURE 106
#define ACAORETORNOFUNCAO 107
#define ACAOATRIBUICAO1 108
#define ACAOATRIBUICAO2 109
#define ACAOPARAMETRO1 110
#define ACAOPUTPAR 111
#define ACAOCOMANDOIF1 112
#define ACAOCOMANDOIF2 113
#define ACAOCOMANDOELSE1 114
#define ACAONAOPARAMETROS 115
#define ACAOCOMANDOREPEAT1 116
#define ACAOCOMANDOREPEAT2 117
#define ACAOCOMANDOWHILE1 118
#define ACAOCOMANDOWHILE2 119
#define ACAOCOMANDOWHILE3 120
#define ACAOCOMANDOFOR1 121
#define ACAOCOMANDOFOR2 122
#define ACAOCOMANDOFOR3 123
#define ACAOCOMANDOFOR4 124
#define ACAOCOMANDOREAD1 125
#define ACAOCOMANDOREAD2 126
#define ACAOCOMANDOREADLN1 127
#define ACAOCOMANDOREADLN2 128
#define ACAOCOMANDOWRITE1 129
#define ACAOCOMANDOWRITE2 130
#define ACAOCOMANDOWRITELN1 131
#define ACAOCOMANDOWRITELN2 132
#define ACAOHALT 133
#define ACAOATRIBUICAO3 134


// constantes para verificacao de precedencia
#define PRECEDENCIAMAIOR 1
#define PRECEDENCIAMENOR 2
#define PRECEDENCIAIGUAL 0
// contande para verificacao do final da cadeia
#define FINALCADEIA 100
// Tamanho do Buffer
#define MAXBUFFER 160
// Tamanho da lista de palavras chaves
#define MAXPC 160
// Tamanho da lista de erros
#define MAXERRO 500

//variavel de verificacao de inicializacao das palavras chaves
int INIPALAVRACHAVE = 1;
//contador de linha
int contLinha =0;
// contador de erros lexico
int contErroLexico = 0;
// contador de erros sintaticos
int contErroSintatico= 0;
// contador de linhas compiladas
int contLinhasCompiladas = 0;

// Matriz de transicao de estados
const int matrizEstados[29][20] =
{
    {1,	18,	11,	24,	25,	3,	6,	10,	14,	15,	17,	16,	-2,	26,	-1,	27,	-1,	-5,	-7,	28},
    {1,	1,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {5,	5,	5,	5,	5,	5,	5,	4,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5,	5},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {9,	9,	9,	9,	9,	8,	9,	7,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9,	9},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {13,	13,	13,	13,	13,	13,	13,	12,	13,	13,	13,	13,	13,	13,	13,	13,	13,	13,	13,	13},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {23,	18,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	21,	19,	23,	23,	23,	23,	23,	23},
    {-2,	20,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2},
    {23,	20,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	21,	23,	23,	23,	23,	23,	23,	23},
    {-2,	22,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2,	-2},
    {23,	22,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23,	23},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1}
};


// Matriz de Acao

const int matrizAcao[26][41] =
{
    {1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 2, 2, 2, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, 3, 3, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, 4, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, 5,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	0,	-1,	0,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, 29, 29, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	7,	7,	-1,	-1},
    {-1, -1, -1, 29, 29, -1, -1, -1, 8,	8,	8,	8,	8, -1, -1, -1, -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, 29, -1, 29, 29, 9, 9, 9, 9, 9, -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	-1,	-1,	0, 10, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 11, 29, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, 29, -1, 12, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1, -1, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, 29, 15,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, 16, -1, -1, -1, -1, 16, 16, 16, 16, 16, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 17, -1, -1, 29,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, 18, -1, -1, -1, -1, 18, 18, 18, 18, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	-1,	-1,	0,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, -1, -1, -1, -1, 19, 19, 19, 19, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,	0,	-1,	-1,	-1,	0, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, 20, 0,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	20,	-1,	-1,	20,	0, 20,	-1,	20,	-1,	20,	20,	20,	20,	-1,	-1,	-1,	-1,	-1,	-1,	20,	-1, -1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, -1, 29, -1, -1, -1, 1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	29, -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	21,	-1,	-1,	-1,	-1,	-1, -1,	-1,	-1,	-1,	-1,	-1,	-1},
    {-1, -1, -1, -1, 22, 29, -1, -1, -1, -1, -1, -1, -1, 22, -1, 29, 22, 29, 22, -1, 22, -1, 22, 22, 22, 22, -1, -1, 29, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, 23, -1, -1, -1, -1, -1, -1, -1, -1, 23, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, 0,	24,	-1,	-1,	-1,	24,	24,	24,	-1,	-1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, 26, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};

// Matriz de Acao
const int matrizPO[11][11] =
{
    {1,	2,	2,	1,	2,	2,	2,	2,	-5,	1,	1},
    {1,	1,	2,	1,	2,	2,	-5,	2,	-5,	1,	1},
    {2,	2,	2,	0,	2,	2,	2,	2,	2,	2,	-2},
    {1,	1,	-1,	1,	-1,	-4,	-4,	-4,	1,	1,	1},
    {1,	1,	2,	1,	-1, -4,	-5,	-4,	1,	1,	1},
    {1,	1,	-1,	1,	-4,	-1,	-5,	-4,	1,	1,	1},
    {1,	-5,	-1,	1,	-4,	-5,	-4,	-4,	1,	1,	1},
    {1,	1,	2,	1,	2,	2,	-4,	2,	-5,	1,	1},
    {-5,	-5,	2,	1,	2,	2,	2,	-5,	1,	-5,	1},
    {2,	2,	2,	1,	2,	2,	2,	2,	-4,	1,	1},
    {2,	2,	2,	-3,	2,	2,	2,	2,	1,	2,	-4}
};


#endif
