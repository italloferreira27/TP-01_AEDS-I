#include <stdio.h>
#include <TADp.h>

//definindo tipo TAD dicionario
//typedef struct Letra;

//definindo TAD dicionario
typedef struct{
    char l;
    Apontador P;
}Tdici;

//definindo tipo celula
typedef struct CelDici *(ApontL);

//definindo celula
typedef struct CelDici{
    Tdici Pala;
    struct CelDici *proxD;
}TCL;

//definindo lista dicionario
typedef struct{
    ApontL priL;
    ApontL ultL;
}TLD;

void iniciarD(TLD *D);
void inserirPinD(TLD *D, ListaPala *pl, TPalavra *obj);
void imprimirLespci(TLD *D);
void imprimirDici(TLD *D);