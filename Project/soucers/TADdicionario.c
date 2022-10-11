#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADdicionario.h"
#include "../headers/TADpalavra.h"

//inicializa lista de letras
void inicia_lista_lista_letra(lista_letra *lista){
    lista->primeiro = (celula_letra *)malloc(sizeof(celula_letra));
    lista->utimo = lista->primeiro;
    lista->utimo->prox = NULL;
}

//insere letra na lista
void insere_letra(lista_letra *lista, letra l){
    celula_letra *aux = lista->primeiro->prox;
    celula_letra *auxAnt = lista->primeiro;
   
   if(lista->primeiro!=lista->utimo){
    
    while(l.letra > aux->Letra.letra && aux != NULL){
            aux = aux->prox;
            auxAnt = auxAnt->prox;
        }
    }

    if(lista->primeiro->prox == NULL || lista->utimo == auxAnt->prox && l.letra > lista->utimo->Letra.letra){
        
        auxAnt->prox = (celula_letra *)malloc(sizeof(celula_letra));
        auxAnt->prox->Letra = l;
        auxAnt->prox->prox = aux;
    
    }else{
    
        lista->utimo->prox = (celula_letra *)malloc(sizeof(celula_letra));
        lista->utimo = lista->utimo->prox;
        lista->utimo->Letra = l;
        lista->utimo->prox = NULL;
        
    } 
}

//verifica se a letra ja exista(chamar para inserir palavra)
int verifica_letra(lista_letra *lista, letra l){
    celula_letra *inicio = lista->primeiro->prox;

    int i,cont;

    while(inicio != NULL){
        if(inicio->Letra.letra == l.letra){
            return 1;
        }
        inicio = inicio->prox;
    }
    insere_letra(lista,l);
    return 0;
}

// imprime lista
void imprimeletra(lista_letra *lista){
    celula_letra *aux = lista->primeiro->prox;

    while(aux != NULL){
        printf("%s\n",aux->Letra.letra);
        //imprime palavra aqui
        aux = aux->prox;
    }

}

//imprime letra dada
void imprimeletradada(lista_letra *lista){
    celula_letra *aux = lista->primeiro->prox;
    char dada;

    scanf("%c",&dada);
    
    while (aux->prox != NULL){
        if(dada == aux->Letra.letra){
            printf("!");
            break;
        }
    }

    printf("%c/n",aux->Letra.letra);
}