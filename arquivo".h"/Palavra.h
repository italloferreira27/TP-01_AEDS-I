#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PALAVRA.H
#define PALAVRA.H

//palavra
typedef struct {
    char palavra[20];
    //lista_linha Linhas;
}Tpalavra;

//celula de palavra *****
typedef struct celulaP{
    Tpalavra Pala;
    struct celulaP *prox;
}celulaP;



#endif