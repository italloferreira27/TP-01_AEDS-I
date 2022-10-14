#include "../headers/TADlinha.h"

int LL_Vazia(Tlista* lista){
    return lista->Primeiro == lista->Ultimo;
}

void LL_Inicializa(Tlista* lista){
    lista->Primeiro = (Apontado) malloc(sizeof(Celula_Linha));
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

void LL_Inserir(Tlista* lista, Titem item){
    lista->Ultimo->prox = (Apontado) malloc(sizeof(Celula_Linha));
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->linha = item;
    lista->Ultimo->prox = NULL;
    printf("Inserido com sucesso!\n");
}

int LL_Imprimir(Tlista* lista){
    Apontado aux;

    if(LL_Vazia(lista)){
        printf("Lista vazia!\n");
        return 0;
    }

    aux = lista->Primeiro->prox;

    printf("Linha: ");
    while(aux != NULL){
        printf("|%d", aux->linha.chave);
        aux = aux->prox;
    }
    printf("|\n");
}

void LL_ExcluirFinal(Lista_Linha* linha){
    if(LL_vazia){
        return 0;
    }
    celula_linha *paux = linha->Primeiro->prox;
    celula_linha *pant = linha->Primeiro;

int LL_ExcluirFinal(Tlista* lista){
    if(LL_Vazia(lista)){
        printf("lista vazia!\n");
        return 0;
    }

    Apontado aux = lista->Primeiro->prox;
    Apontado ant = lista->Primeiro;

    while(aux != NULL){
        if(aux->prox == NULL){
            aux = lista->Ultimo;
            lista->Ultimo = ant;
            lista->Ultimo->prox = NULL;
            free(aux);
            printf("EXCLUIDO!\n");
            return 0;
        }
        aux = aux->prox;
        ant = ant->prox;
    }
}

int LL_ExcluirEspecifico(Tlista* lista, int item){
    Apontado aux = lista->Primeiro->prox;
    Apontado ant = lista->Primeiro;

    if(LL_vazia){
        return 0;
    }

    while(paux != num){
        paux = paux->prox;
        pant = pant->prox;
    }
    if(paux != NULL){
        pant->prox = paux->prox;
        free(paux);
    }
}