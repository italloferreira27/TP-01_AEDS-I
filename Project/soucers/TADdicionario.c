#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADdicionario.h"
#include "../headers/TADpalavra.h"

//iniciar TAD dicionario
void IniciarDici(TlistaL *dici){
    dici->PrimeiroL = (ApontaL) malloc(sizeof(celulaL));
    dici->UltimoL = dici->PrimeiroL;
    dici->PrimeiroL->proxL = NULL;
}

void InserirPala(TlistaL *dici, ListaPala *lp, TPalavra item){
    ApontaL aux;
    int result;
    char l,pala[50];

    strcpy(pala, item.item);
    l = item.item[0];


    aux = dici->PrimeiroL->proxL;
    while (aux != NULL){
        if(aux->Let.L == l){
            result = 0;
        }    
        //result = (strcmp(aux->Let.L, letra));    
    }
    if(result != 0){
        dici->UltimoL->proxL = (ApontaL) malloc(sizeof(celulaL));
        dici->pala = lp->Primeiro;
        InserirElemLP(lp, item, pala);
    }      

}