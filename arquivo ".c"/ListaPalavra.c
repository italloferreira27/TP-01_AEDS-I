#include "ListaPalavra.h"

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

//remove palavra(dada a palavra)*****
void removeP(lista_palavra *list,Tpalavra p){
    celulaP *pAux = list->primeiro->prox;
    celulaP *pAnt = list->primeiro;

    while(strcmp(pAux->Pala.palavra,p.palavra) != 0){
        pAux = pAux->prox;
        pAnt = pAnt->prox;
    }
    if(pAux != NULL){
        pAnt->prox = pAux->prox;
        free(pAux);
    }
}

//remove palavra (final)*****
void retiraP_final(lista_palavra *list){
    celulaP *inicio,*aux = list->utimo;
    list->utimo = list->anterior;
    list->utimo->prox = NULL;

    free(aux);

    inicio = list->primeiro;
    while(inicio != list->utimo){
        inicio = inicio->prox;
    }
    list->anterior = inicio;
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

//retorna tamanho da lista
int gettamanhoListaP(lista_palavra *list){
    return list->tamanho;
}