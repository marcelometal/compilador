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
#include "scanner.h"

//declaraçoes globais
apont ponteiro1 = NULL;
tipoLista l;
listaErro e;

/**
 * Função usada para criar uma lista vazia
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void criaLista(tipoLista *l)
{
    l->primeiro = (apont) malloc(sizeof(celula));
    l->ultimo = l->primeiro;
    l->primeiro->prox = NULL;
}


/**
 * Função usada para verficica se a lista está fazia
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int vaziaLista(tipoLista l)
{
    return l.primeiro == l.ultimo;
}


/**
 * Função usada para inserir um token na lista
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void insereToken(tipoToken x, tipoLista *l)
{
    l->ultimo->prox = (apont) malloc(sizeof(celula));
    l->ultimo = l->ultimo->prox;
    l->ultimo->item = x;
    l->ultimo->prox = NULL;
}


/**
 * Função que lê do arquivo fonte e armazena no buffer
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void lerLinhaFonte(buffer *vetBuffer, int qtdeCaracteres, FILE *arq)
{
    fgets(vetBuffer->valor, qtdeCaracteres, arq);
    contLinha++;
}

/**
 * Função usada para inicializar os valores do buffer
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void iniciaBuffer(buffer *x)
{
    x->inicio = 0;
    x->posicao = x->inicio;
}

/**
 * Função usada para gerar a tabela de tokens e de erros exibindo-as na tela
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void aLexico(char arquivo[15])
{
    // inicialiçao da lista de tokens
    criaLista(&l);

    // inicialiçao da lista de erros
    criaListaErro(&e);

    // geracao da lista de erros e tokens
    retornarListaToken(&l, &e, arquivo);

    //exibe a lista de tokens
    /*     if(!vaziaLista(l))
           imprimeListaToken(l);
    //pula de linha
    ENTER;
    //exibe a lista de erros
    if (!vazia(e))
    imprimirErro(e); */
}

/**
 * Função usada para ler o proximo caracter
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
char lerProxCaractere(buffer *vetBuffer)
{
    return vetBuffer->valor[vetBuffer->posicao];
}


/**
 * Função usada para retrocede um caractere no Buffer
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void retroceder(buffer *vetBuffer)
{
    vetBuffer->posicao--;
}

/**
 * Função usada para verificar se pode avançar caractere
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
char verificarAvancarCaractere(FILE *arq, buffer *vetBuffer, char c)
{
    if (c == '\t') {
        avancarCaractere(vetBuffer);
        c = lerProxCaractere(vetBuffer);
        avancarToken(vetBuffer);
        return verificarAvancarCaractere(arq, vetBuffer, c);
    }
    return c;
}


/**
 * Função usada eliminar os espaços em branco
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void eliminaEspacos(buffer *vetBuffer)
{
    while (vetBuffer->valor[vetBuffer->inicio] == ' '
            || vetBuffer->valor[vetBuffer->inicio] == '\n'
            || vetBuffer->valor[vetBuffer->inicio] == 13)
        vetBuffer->inicio++;
    if (vetBuffer->posicao < vetBuffer->inicio)
        vetBuffer->posicao = vetBuffer->inicio;
}

/**
 * Função usada eliminar os espaços em branco do final do buffer e caracteres especiais
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void eliminaEspacosFinal(buffer *vetBuffer)
{
    int k = strlen(vetBuffer->valor);
    while (vetBuffer->valor[k - 1] == '\n'
            || vetBuffer->valor[k - 1] == ' '
            || vetBuffer->valor[k - 1] == 13)
        k--;
    vetBuffer->valor[k] = '\0';
}


/**
 * Função usada para avançar o ponteiro para o próximo token
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void avancarToken(buffer *vetBuffer)
{
    vetBuffer->inicio = vetBuffer->posicao;
}

/**
 * Função usada para avançar o ponteiro para o próximo caracter
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void avancarCaractere(buffer *vetBuffer)
{
    vetBuffer->posicao++;
}

/**
 * Função usada para verificar se o ponteiro esta no final do buffer
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int finalBuffer(buffer *b)
{
    if (b->posicao == MAXBUFFER || b->valor[b->posicao] == '\0')
        return 1;
    return 0;
}


/**
 * Função usada para retorna o valor da coluna na Matriz de Transição
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int retornaColuna(char caractere, int estado)
{
    int verifica;
    if (estado >= 18 && estado <= 23
            && (caractere == 'E' || caractere == 'e'))
        verifica = 0;
    else
        verifica = 1;
    if (isalpha(caractere) && verifica)
        return 0;
    else if (isdigit(caractere))
        return 1;
    switch (caractere) {
        case '\0':{
                      return 14;
                  }
        case ':':{
                     return 2;
                 }
        case '(':{
                     return 3;
                 }
        case ')':{
                     return 4;
                 }
        case '>':{
                     return 5;
                 }
        case '<':{
                     return 6;
                 }
        case '=':{
                     return 7;
                 }
        case '+':{
                     return 8;
                 }
        case '-':{
                     return 9;
                 }
        case '/':{
                     return 10;
                 }
        case '*':{
                     return 11;
                 }
        case 'E':{
                     return 12;
                 }
        case 'e':{
                     return 12;
                 }
        case '.':{
                     return 13;
                 }
        case ' ':{
                     return 14;
                 }
        case ';':{
                     return 15;
                 }
        case '\n':{
                      return 16;
                  }
        case '{':{
                     return 17;
                 }
        case '\'':{
                      return 18;
                  }
        case ',':{
                     return 19;
                 }
    }
    return -1;
}


/**
 * Função usada para retorna o token encontrado
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
tipoToken retornarToken(char arquivo[15], buffer *vetbuffer, int classe)
{
    tipoToken x;
    x.classe = classe;
    strcpy(x.lexema, substring(vetbuffer));
    strcpy(x.nomeArq, arquivo);
    x.linha = contLinha;
    x.coluna = vetbuffer->posicao - 1;
    return x;
}

/**
 * Função usada para retorna uma substring do buffer
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
char *substring(buffer *b)
{
    char *strValor = (char *) malloc(160 * sizeof(char));
    int i, j = 0;
    for (i = b->inicio; i < b->posicao; i++) {
        strValor[j] = b->valor[i];
        j++;
    }
    strValor[j] = '\0';
    return strValor;
}


/**
 * Função usada para eliminar comentários
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int eliminarComentario(FILE *arq, buffer *b)
{
    while (b->valor[b->posicao] != '}') {
        if (!finalBuffer(b)) {
            avancarCaractere(b);
        }

        else {
            lerLinhaFonte(b, 160, arq);
            iniciaBuffer(b);
        }
        if (feof(arq))
            return -6;
    }
    avancarCaractere(b);
    return 0;
}


/**
 * Função usada para verifica qual foi o erro e insere o mesmo na lista de erros
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void verificarErro(listaErro *e, int estado, buffer *b)
{
    switch (estado) {
        case -2:{
                    tErro erro2 = recuperarErro(contLinha, -2,
                            substring(b));
                    inserirErro(erro2, e);
                    break;
                }
        case -3:{
                    tErro erro3 = recuperarErro(contLinha, -3,
                            substring(b));
                    inserirErro(erro3, e);
                    break;
                }
        case -4:{
                    tErro erro4 = recuperarErro(contLinha, -4,
                            substring(b));
                    inserirErro(erro4, e);
                    break;
                }
        case -6:{
                    tErro erro6 = recuperarErro(contLinha, -6,
                            substring(b));
                    inserirErro(erro6, e);
                    break;
                }
    }
}


/**
 * Função usada para retornar um literal ou se não um erro
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
int retornaLiteral(FILE *arq, buffer *b, char lexema[160])
{
    avancarCaractere(b);
    avancarToken(b);
    while (b->valor[b->posicao]
            != '\'') {
        if (!finalBuffer(b))
            avancarCaractere(b);
        else {
            strcat(lexema, substring(b));
            lerLinhaFonte(b, 160, arq);
            iniciaBuffer(b);
        }
        if (feof(arq))
            return -4;
    }
    avancarCaractere(b);
    if (b->valor[b->posicao] == '\'') {
        strcat(lexema, substring(b));
        strcat(lexema, "'");
        return retornaLiteral(arq, b, lexema);
    }
    strcat(lexema, substring(b));
    return 0;
}


/**
 * Função usada para converter uma string minuscula para maiscula
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
char *converteMaiusculo(char lexema[160])
{
    char *strValor = (char *) malloc(160 * sizeof(char));
    int j;
    for (j = 0; j < strlen(lexema); j++)
        strValor[j] = toupper(lexema[j]);
    strValor[j] = '\0';
    return strValor;
}

/**
 * Função usada para imprimir a lista de tokens na tela
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void imprimeListaToken(tipoLista lista)
{
    int i = 0;
    tipoToken x = proximoToken();
    printf
        ("Classe\t\t\tLexema\t\t\tLinha\t\t\tcoluna\t\t\tNome do Arquivo\n");
    for (i = 0; i < 110; i++)
        printf("-");
    ENTER;
    while (x.classe != FINALARQ) {
        printf("%d\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%s\n",
                x.classe, x.lexema, x.linha, x.coluna, x.nomeArq);
        x = proximoToken();
    }
    printf
        ("%d\t\t\t%s\t\t\t%d\t\t\t%d\t\t\t%s\n",
         x.classe, x.lexema, x.linha, x.coluna, x.nomeArq);
}

/**
 * Função usada para gerar a lista de tokens  e a lista de erros
 *
 * @since 18/09/2003
 * @author Érix Henrique Gontijo Morato <erixhe@yahoo.com.br>
 * @author Marcelo Jorge Vieira <metal@alucinados.com>
 * @access public
 */
void retornarListaToken(tipoLista *l, listaErro *e, char arquivo[15])
{

    //declaracoes
    buffer vetBuffer;
    int numColuna = 0;
    int estado = 0;
    int estadoAnterior = 0;
    char caractere = ' ';
    tipoToken x;
    // abertura do arquivo fonte
    FILE *arq = abreArquivo(arquivo);
    // verifica se as palavras chaves ja foram adicionadas
    if (INIPALAVRACHAVE) {
        // inicialiçao da lista de palavras chaves
        inicializaPc();
        // geracao da tabela de palavras chaves
        inserirPalavraChave();
    }
    // Ler a primeira linha do arquivo e insere no buffer
    lerLinhaFonte(&vetBuffer, 160, arq);
    while (!feof(arq)) {
        // inicialiçao do buffer
        iniciaBuffer(&vetBuffer);
        eliminaEspacosFinal(&vetBuffer);
        while (!finalBuffer(&vetBuffer)) {
            eliminaEspacos(&vetBuffer);
            estado = 0;
            estadoAnterior = 0;
            while (estado >= 0) {
                caractere = lerProxCaractere(&vetBuffer);
                caractere =
                    verificarAvancarCaractere
                    (arq, &vetBuffer, caractere);
                numColuna =
                    retornaColuna(caractere, estado);
                if (numColuna < 0 && !estado) {
                    estado = -3;
                    avancarCaractere(&vetBuffer);
                    break;
                }

                else if (numColuna < 0 && estado) {
                    numColuna = CARACTERE_ESPECIAL;
                }
                estadoAnterior = estado;
                estado = matrizEstados[estado]
                    [numColuna];
                if (estado >= 0)
                    avancarCaractere(&vetBuffer);
            }
            if (estado == -1) {
                switch (estadoAnterior) {
                    case 2:
                        {
                            /*ID ou Palavra Chave */
                            retroceder(&vetBuffer);
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    pesquisaPc
                                    (converteMaiusculo
                                     (substring
                                      (&vetBuffer))));
                            insereToken(x, l);
                            break;
                        }
                    case 4:
                        {


                            /*Relop >= */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    RELOP);
                            insereToken(x, l);
                            break;
                        }
                    case 5:
                        {


                            /*Relop > */
                            retroceder(&vetBuffer);
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    RELOP);
                            insereToken(x, l);
                            break;
                        }
                    case 7:
                        {


                            /*Relop <= */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    RELOP);
                            insereToken(x, l);
                            break;
                        }
                    case 8:
                        {


                            /*Relop <> */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    RELOP);
                            insereToken(x, l);
                            break;
                        }
                    case 9:
                        {


                            /*Relop < */
                            retroceder(&vetBuffer);
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    RELOP);
                            insereToken(x, l);
                            break;
                        }
                    case 10:
                        {


                            /*Relop = */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    RELOP);
                            insereToken(x, l);
                            break;
                        }
                    case 12:
                        {


                            /*Atrib := */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    ATRIB);
                            insereToken(x, l);
                            break;
                        }
                    case 13:
                        {


                            /*Dois Pontos : */
                            retroceder(&vetBuffer);
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    DOISPONTOS);
                            insereToken(x, l);
                            break;
                        }
                    case 14:
                        {

                            /*Addop + */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    ADDOP);
                            insereToken(x, l);
                            break;
                        }
                    case 15:
                        {

                            /*Addop - */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    ADDOP);
                            insereToken(x, l);
                            break;
                        }
                    case 16:
                        {

                            /*Multop * */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    MULTOP);
                            insereToken(x, l);
                            break;
                        }
                    case 17:
                        {

                            /*Multop / */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    MULTOP);
                            insereToken(x, l);
                            break;
                        }
                    case 23:
                        {

                            /*Num */
                            retroceder(&vetBuffer);
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    NUM);
                            insereToken(x, l);
                            break;
                        }
                    case 24:
                        {

                            /*Abrepar ( */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    ABREPAR);
                            insereToken(x, l);
                            break;
                        }
                    case 25:
                        {

                            /*Fecha Par */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    FECHAPAR);
                            insereToken(x, l);
                            break;
                        }
                    case 26:
                        {

                            /*PONTO */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    PONTO);
                            insereToken(x, l);
                            break;
                        }
                    case 27:
                        {

                            /*PONTOVIRGULA */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    PONTOVIRGULA);
                            insereToken(x, l);
                            break;
                        }
                    case 28:
                        {

                            /*VIRGULA */
                            x = retornarToken(arquivo,
                                    &vetBuffer,
                                    VIRGULA);
                            insereToken(x, l);
                            break;
                        }
                }
            }

            else {
                switch (estado) {
                    case -5:

                        {
                            estado =
                                eliminarComentario(arq,
                                        &vetBuffer);
                            break;
                        }
                    case -7:
                        {
                            strcpy(x.lexema, "'");
                            estado =
                                retornaLiteral(arq,
                                        &vetBuffer,
                                        x.lexema);
                            /*LITERAL*/ if (!estado) {
                                x.classe = LITERAL;
                                strcpy(x.nomeArq,
                                        arquivo);
                                x.linha =
                                    contLinha;
                                x.coluna =
                                    vetBuffer.posicao
                                    - 1;
                                insereToken(x, l);
                            }
                            break;
                        }
                }
                verificarErro(e, estado, &vetBuffer);
                if ((estado == -4)
                        || (estado == -6))
                    goto fim;
            }
            avancarToken(&vetBuffer);
        }
        lerLinhaFonte(&vetBuffer, 160, arq);
    }

    //label FIM
fim:
    //final do arquivo
    strcpy(x.lexema, "EOF");
    x.classe = FINALARQ;
    strcpy(x.nomeArq, arquivo);
    x.linha = contLinha;
    x.coluna = vetBuffer.posicao - 1;
    insereToken(x, l);
    // Fecha o arquivo
    if (!fechaArquivo(arq)) {
        printf("ERROR ao fechar o arquivo");
    }
    ponteiro1 = l->primeiro;
}

tipoToken proximoToken()
{
    tipoToken x;
    if (ponteiro1->prox->item.classe != FINALARQ) {
        if (ponteiro1->prox != NULL) {
            x = ponteiro1->prox->item;
            ponteiro1 = ponteiro1->prox;
        }
    }

    else {
        x = ponteiro1->prox->item;
    }
    return x;
}
