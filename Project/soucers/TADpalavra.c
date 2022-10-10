#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADpalavra.h"

//verificar se a lista esta vazia
int ListaVaziaLP(ListaPala *LP){
    return (LP->Primeiro == LP->Ulitmo); 
}

//inicializar o Lista Palavra
void InicializarLP(ListaPala *LP){
    LP->Primeiro = (Apontador) malloc(sizeof(celulapalavra));
    LP->Ulitmo = LP->Primeiro;
    LP->Primeiro->prox = NULL;
    LP->nroElem = 0;
}

//inserir nova Lista de Palavra //funcao 1
void InserirElemLP(ListaPala *LP, TPalavra item, char *charptr){
    //result para verificar se a palavra ja exite
    int result;
    result = ProcurarLP(LP, charptr);

    if(result == 0){
        LP->Ulitmo->prox = (Apontador) malloc(sizeof(celulapalavra));
        LP->Ulitmo = LP->Ulitmo->prox;
        if(LP->Ulitmo != NULL){ //espaco esta disponivel
            LP->Ulitmo->palavra = item; 
            LP->Ulitmo->prox = NULL;
        }
        LP->nroElem++;
    }
}

//imprimi Lista de Palavra
void ImprimirLP(ListaPala *LP){
    Apontador aux;
    aux = LP->Primeiro->prox;
    //verificar se a lista esta vazia
    if(ListaVaziaLP(LP)){
        printf("Lista esta Vazia.\n");
        return; 
    }

    while (aux != NULL){
        printf("-----------------------\n");
        printf("palavra: %s\n",aux->palavra.item);
        printf("Linhas: \n");
        printf("-----------------------\n");
        aux = aux->prox;
    }
    return;
}

//imprimi a palavra desejada
void ImprimirLPespecifica(ListaPala *LP, char *pl){
    Apontador aux;
    int result,r;
    aux = LP->Primeiro->prox;

    //verificar se elemento existe
    r = ProcurarLP(LP,pl);

    if(r == 1){
        printf("Palavra existe.\n");
        while (aux != NULL){
        result = strcmp(aux->palavra.item, pl);
        if(result == 0){
            printf("%s\n",aux->palavra.item);
        }
        aux = aux->prox;
        }
    }
    else{
        printf("Palavra nao existe.\n");
    }
    return;
}

int ProcurarLP(ListaPala *LP, char *pl){ //funcao 2
    Apontador aux;
    int result;
    aux = LP->Primeiro->prox;

    while (aux != NULL){
        result = strcmp(aux->palavra.item, pl);
        if(result == 0){
            //printf("Palavra existe.\n");
            return 1;
        }
        aux = aux->prox;
    }
    //printf("Palavra nao existe.\n");
    return 0;
}

//excluir lista que tenha elemento que o usuario pediu
void ExcluirElemLPEspecifico(ListaPala *LP, char *pl){ //funcao 3
    Apontador ANTptr; //guardar posicao celula anterior
    Apontador aux;
    Apontador Cauxptr;
    int result;
    ANTptr = LP->Primeiro;
    aux = LP->Primeiro->prox;
    
    //verificar se a lista estavazia
    if(ListaVaziaLP(LP)){
        printf("Lista esta Vazia.\n");
        return; 
    }
    //verficar se o elemento existe
    result = ProcurarLP(LP,pl);
    if(result == 0){
        printf("Palavra nao existe.\n");
        return;
    }

    while (aux != NULL){
        result = strcmp(aux->palavra.item, pl);
        if(result == 0){
            Cauxptr = aux;
            ANTptr->prox = aux->prox;
            free(Cauxptr);
            printf("Palavra removida.\n");
            return;
        }
        ANTptr = ANTptr->prox;
        aux = aux->prox;
    }
}

//excluir o ultimo elemento
void ExcluirElemLPfinal(ListaPala *LP){ //funcao 4
    Apontador ANTptr; //guardar posicao celula anterior
    Apontador aux;
    Apontador Cauxptr;
    int result;
    ANTptr = LP->Primeiro;
    aux = LP->Primeiro->prox;
    
    //verificar se a lista estavazia
    if(ListaVaziaLP(LP)){
        printf("Lista esta Vazia.\n");
        return; 
    }

    while (1){
        if(aux->prox == NULL){
            Cauxptr = LP->Ulitmo;
            LP->Ulitmo = ANTptr;
            LP->Ulitmo->prox = NULL;
            free(Cauxptr);
            printf("Ultima palavra removida.\n");
            return;
        }
        ANTptr = ANTptr->prox;
        aux = aux->prox;
    }
}

//retornar quantidade de palavras
int TamanhoLP(ListaPala LP){ //funcao 8
    return LP.nroElem;
}


void InstrucoesLP(void){
    printf("Digite sua escolha:\n"
    "1 para inserir um elemento na lista.\n"
    "2 para para procurar se elemento existe.\n"
    "3 para excluir um elemento na lista.\n"
    "4 para excluir um elemento no final da lista.\n"
    "5 para exibir quantas palavras existem.\n"
    "6 para imprimir a lista de palavras.\n"
    "7 para imprimir palavra desejada e suas linhas.\n"
    "8 para terminar.\n");
}
