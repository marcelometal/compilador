#ifndef parserH
#define parserH

// bibliotecas
# include "scanner.c"
# include "definicoesC3E.c"

// estrutura da pilha para analisador sintatico com precedencia de operadores
typedef struct pASPO
{
char tipo;
char lexema[160];
union
{
int nt;
tipoToken t;
} SG;
} tipoASPO;

// estrutura para a pilha do analisador sintatico com precedencia de operadores
typedef struct nodoPilhaASPO *apontASPO;
typedef struct nodoPilhaASPO
{
tipoASPO item;
apontASPO prox;
apontASPO ant;
} celulaASPO;
typedef struct pilhaASPO
{
apontASPO topo,fundo;
} tipoPilhaASPO;

// estrutura da pilha para analisador sintatico preditivo
typedef struct pASP
{
int simboloGram;
} tipoASP;

// estrutura para a pilha do analisador sintatico preditivo
typedef struct nodoPilhaASP *apontASP;
typedef struct nodoPilhaASP
{
tipoASP item;
apontASP prox;
} celulaASP;
typedef struct pilhaASP
{
apontASP topo,fundo;
} tipoPilhaASP;

//prototipos
void criaPilhaASPO(tipoPilhaASPO *p);
void criaPilhaASP(tipoPilhaASP *p);
void empilhaASPO(tipoASPO x, tipoPilhaASPO *p);
void empilhaASP(tipoASP x, tipoPilhaASP *p);
void desempilhaASPO(tipoPilhaASPO *p);
void desempilhaASP(tipoPilhaASP *p);
void imprimePilhaASPO(tipoPilhaASPO p);
void imprimePilhaASP(tipoPilhaASPO p);
int retornarColunaMatrizAcao(int classe);
int retornarLinhaMatrizAcao(int nTerminal);
int retornarAcao(int terminal, int nTerminal);
tipoASP retornarTipoASP(int classe);
void aSintatico();
int isTerminal(int classe);
int finalASintatica(int simboloGram, int classe);
tipoASPO retornarTipoASPO(int simboloGram, tipoToken token, char tipo);
void executarASintatica(tipoPilhaASP *p,tipoPilhaASPO *q);
void panico(tipoPilhaASP *p,tipoToken *x,int *linha);
int verificarSincronismo(int simboloGram,int classe);
tErro retornaErro(int simboloGram,tipoToken x);
int finalASPO(char tipo,int simboloGram, int classe);
int retornarLinhaColunaMatrizPO(int classe);
int verificaExistenciaToken(int classe);
void executarAPO(tipoPilhaASPO *q,tipoToken *x,int *linha,FILE *arqC3E);
void gerarEstatistica();
tErro complementaFrase(int codigo,tipoPilhaASPO *q,tipoToken *x,tipoPilha *pTemp,FILE *arqC3E);
int testarErro(int classe);
int possivelReducao(char strValor[20], tipoPilha *pTemp, char lexema[160],FILE *arqC3E);
void executarReducao(FILE *arqC3E,tipoPilhaASPO *q,tipoToken *x,tipoPilha *pTemp);
apontASPO retornarUltimoTerminal(tipoPilhaASPO *q);

#endif
