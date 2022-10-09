#include "TADpalavra.h"

//definfindo TAD dicionario
typedef char Letra;

//declarando TAD dicionario
typedef struct{
    Letra L;
}Tdicionario;

//declarando apontador para letra
typedef struct celulaL *ApontaL;

//declarando celula do TADdicionario
typedef struct celulaL{
    Tdicionario Let;//cada letra
    struct celulaL *proxL;
}celulaL;

//declarando Lista de letras
typedef struct{
    ApontaL PrimeiroL;
    ApontaL UltimoL;
    ApontaL pala; //cada celular apontara para sua letra em especifico
}TlistaL;

//prototipos
void IniciarDici(TlistaL *dici);
void InserirPala(TlistaL *dici, ListaPala *lp, TPalavra item);
void ImprimeLEspeci(TlistaL *dici, char);
void ImprimeDici(TlistaL *dici);
