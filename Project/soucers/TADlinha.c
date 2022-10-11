#include "../headers/TADlinha.h"


int LL_vazia(Lista_Linha *linha){
    return linha->Primeiro == linha->Ultimo; 
}

void LL_Inicializa(Lista_Linha *linha){
    linha->Primeiro = (Apontado) malloc(sizeof(celula_linha));
    linha->Ultimo = linha->Primeiro;
    linha->Primeiro->prox = NULL;
}

void LL_Inserir(Lista_Linha *linha, Tlinha* num){
    linha->Ultimo->prox = (Apontado) malloc(sizeof(celula_linha));
    linha->Ultimo = linha->Ultimo->prox;
    linha->Ultimo->NumLinha = *num;
    linha->Ultimo->prox = NULL;
}

void LL_Imprimir(Lista_Linha* linha){
    Apontado aux;
    aux = linha->Primeiro->prox;
    
    printf("Linhas: ");
    while(aux != NULL){
        printf("|%d|", aux->NumLinha.l);
        aux = aux->prox;
    }
}

void LL_ExcluirFinal(Lista_Linha* linha){
    if(LL_vazia){
        return;
    }
    celula_linha *paux = linha->Primeiro->prox;
    celula_linha *pant = linha->Primeiro;

    while(paux->prox != NULL){
        paux = paux->prox;
        pant = pant->prox;
    }

    if(paux != NULL){
        pant->prox = paux->prox;
        free(paux);
    }

}

void LL_ExcluirEspecifico(Lista_Linha* linha, Tlinha* num){
    Apontado paux = linha->Primeiro->prox;
    Apontado pant = linha->Primeiro;    

    if(LL_vazia){
        return;
    }

    while(paux->NumLinha.l != num){
        paux = paux->prox;
        pant = pant->prox;
    }
    if(paux != NULL){
        pant->prox = paux->prox;
        free(paux);
    }
}