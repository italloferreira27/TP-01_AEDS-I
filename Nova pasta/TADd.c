#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADd.h"
#include "TADp.h"

void iniciarD(TLD *D){
    D->priL = (ApontL) malloc(sizeof(CelDici));
    D->ultL = D->priL;
    D->priL->proxD == NULL;
}

void inserirPinD(TLD *D, ListaPala *pl, TPalavra obj){
    ApontL aux;
    int cont=0;
    aux = D->priL->proxD;
    char l,palavra;

    l = obj->item[0];
    strcpy(palavra, obj.item);

    while(aux != NULL){
        if(aux->Pala.l == l){
            cont++;
        }
        aux = aux->proxD;
    }

    aux = D->priL->proxD;

    //verificar se ja existe letra no dicionario
    if (cont == 0){
        D->ultL->proxD = (ApontL) malloc(sizeof(CelDici));
        D->ultL->Pala.l = l;
        InserirElemLP(lp, obj, palavra);
        D->ultL->Pala.P = pl->Ulitmo;
    }
    
    else{
        InserirElemLP(lp, obj, palavra);
        if(aux->Pala.l == l){
            aux->Pala.P = pl->Ulitmo;
        }
        aux = aux->proxD;
    }
}