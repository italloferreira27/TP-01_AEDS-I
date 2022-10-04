#include "ListaPalavra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcao inicializa lista de palavras ******
void inicializa_listaP(lista_palavra *listP){
    listP->primeiro = (celulaP *)malloc(sizeof(celulaP));
    listP->utimo = listP->primeiro;
    listP->utimo->prox = NULL;
    listP->tamanho = 0;
}

//funcao verifica se a palavra ja esta na lista *****
int palavraex(lista_palavra *list, Tpalavra p){
    celulaP *inicio = list->primeiro->prox;
    int i,cont;

    while(inicio != NULL){
        i = strcmp(p.palavra,inicio->Pala.palavra);
        if(i==0){
            return 1;
        }
        inicio = inicio->prox;
    }
    return 0;
}

//funcao adiciona palavra no final da lista*****
void adicionarP(lista_palavra *list,Tpalavra p){
    int verificador;
    verificador = palavraex(list,p);
    if(verificador == 0){
        list->utimo->prox = (celulaP *)malloc(sizeof(celulaP));
        list->anterior =list->utimo;
        list->utimo = list->utimo->prox;
        list->utimo->Pala = p;
        list->utimo->prox = NULL;
        list->tamanho++;
        }
    
    
}

//funcao iprime a lista ******
void imprime(lista_palavra *list){
    celulaP *inicio = list->primeiro->prox;

    while(inicio != NULL){
        printf("%s\n",inicio->Pala.palavra);
        inicio = inicio->prox;
    }
}