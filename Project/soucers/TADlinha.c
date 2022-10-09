#include "../headers/TADlinha.h"


int LL_vazia(Lista_Linha *linha){
    return linha->Primeiro == linha->Ultimo; 
}

void LL_Inicializa(Lista_Linha *linha){
    linha->Primeiro = (Apontador) malloc(sizeof(celula_linha));
    linha->Ultimo = linha->Primeiro;
    linha->Primeiro->prox = NULL;
}

void LL_Inserir(Lista_Linha *linha, Tlinha* num){
    linha->Ultimo->prox = (Apontador) malloc(sizeof(celula_linha));
    linha->Ultimo = linha->Ultimo->prox;
    linha->Ultimo->NumLinha = *num;
    linha->Ultimo->prox = NULL;
}

void LL_Imprimir(Lista_Linha* linha){
    Apontador aux;
    aux = linha->Primeiro->prox;
    
    printf("Linhas: ");
    while(aux != NULL){
        printf("|%d|", aux->NumLinha.l);
        aux = aux->prox;
    }
}