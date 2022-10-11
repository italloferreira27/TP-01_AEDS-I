#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADdicionario.h"
#include "TADpalavra.h"

//inicializar o Lista Palavra
/*void InicializarLP(letra *LP){
    LP->palavras = (ListaPala *)malloc(sizeof(ListaPala));
    LP->palavras->Primeiro = (Apontador) malloc(sizeof(celulapalavra));
    LP->palavras->Ulitmo = LP->palavras->Primeiro;
    LP->palavras->Ulitmo->prox= NULL;
    LP->palavras->nroElem = 0; 
}*/

//inicializa lista de letras
void inicia_lista_lista_letra(lista_letra *lista, ListaPala *pala){
    lista->primeiro = (celula_letra *)malloc(sizeof(celula_letra));
    lista->utimo = lista->primeiro;
    lista->utimo->prox = NULL;
}

//insere letra na lista
void insere_letra(lista_letra *lista, letra l, char *charptr){
    celula_letra *aux = lista->primeiro->prox;
    celula_letra *auxAnt = lista->primeiro;
   
    if(lista->primeiro!=lista->utimo){
    
    while(l.letra > aux->Letra.letra && aux != NULL){
            aux = aux->prox;
            auxAnt = auxAnt->prox;
        }
    //printf("%c",aux->Letra.letra);
    auxAjuda = aux->prox;
    aux->prox = NULL;
    aux->prox = (celula_letra *)malloc(sizeof(celula_letra));
    aux->prox->Letra = l;
    aux = aux->prox;
    aux->prox = auxAjuda; 
    }

    



    /*if(lista->primeiro->prox == NULL || lista->utimo == auxAnt->prox && l.letra > lista->utimo->Letra.letra){
        
        auxAnt->prox = (celula_letra *)malloc(sizeof(celula_letra));
        auxAnt->prox->Letra = l;
        auxAnt->prox->prox = aux;
    
    }else{
    
        lista->utimo->prox = (celula_letra *)malloc(sizeof(celula_letra));
        lista->utimo = lista->utimo->prox;
        lista->utimo->Letra = l;
        lista->utimo->prox = NULL;
        /*InicializarLP(pala);
        InserirElemLP(pala, obj, charptr);*/
        
        
    
    }else{
        
        auxAnt->prox = (celula_letra *)malloc(sizeof(celula_letra));
        auxAnt->prox->Letra = l;
        auxAnt->prox->prox = aux;
        printf("!");
        
    } 
}

//verifica se a letra ja exista(chamar para inserir palavra)
int verifica_letra(lista_letra *lista, letra l, char *charptr){
    celula_letra *inicio = lista->primeiro->prox;
    //printf("%s",palavra);

    int i,cont;
   
    while(inicio != NULL){
        if(inicio->Letra.letra == l.letra){
            
            InserirElemLP(inicio->Letra.Pala,inicio->Letra.Pala->Ulitmo->palavra,charptr);
            return 1;
        }
        inicio = inicio->prox;
    } 
    l.Pala = (ListaPala *)malloc(sizeof(ListaPala));
    InicializarLP(l.Pala);
    //l.palavras->Ulitmo->palavra.item = palavra;
    InserirElemLP(l.Pala,l.Pala->Ulitmo->palavra,charptr);
    insere_letra(lista,l,charptr);
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

    scanf("%s",&dada);
    
    while (aux->prox != NULL){
        if(dada == aux->Letra.letra){
            printf("!");
            break;
        }
    }

    printf("%c/n",aux->Letra.letra);
}