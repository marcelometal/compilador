#ifndef arquivoH
#define arquivoH

//biblioteca
#include "arquivo.c"

//Prototipos
FILE *criaArquivo(char *f);
FILE *abreArquivo(char *f);
int fechaArquivo(FILE *f);

#endif
