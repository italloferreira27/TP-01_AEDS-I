#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADdicionario.h"
#include "../headers/TADpalavra.h"

//inicializar o Lista Palavra
/*void InicializarLP(letra *LP){
    LP->palavras = (ListaPala *)malloc(sizeof(ListaPala));
    LP->palavras->Primeiro = (Apontador) malloc(sizeof(celulapalavra));
    LP->palavras->Ulitmo = LP->palavras->Primeiro;
    LP->palavras->Ulitmo->prox= NULL;
    LP->palavras->nroElem = 0; 
}*/

//inicializa lista de letras
void inicia_lista_lista_letra(lista_letra *lista){
    lista->primeiro = (celula_letra *)malloc(sizeof(celula_letra));
    lista->utimo = lista->primeiro;
    lista->utimo->prox = NULL;
    //lista->primeiro->Letra.Pala = NULL;
}

//insere letra na lista
void insere_letra(lista_letra *lista, letra l, char *charptr){
    celula_letra *aux = lista->primeiro->prox;
    celula_letra *auxAnt = lista->primeiro;
    Apontador AUXptr;
   
   if(lista->primeiro!=lista->utimo){
    
    while(l.letra >= aux->Letra.letra && aux->prox != NULL){
            aux = aux->prox;
            auxAnt = auxAnt->prox;
        }
    }

    if(lista->primeiro->prox == NULL || lista->utimo == auxAnt->prox && l.letra > lista->utimo->Letra.letra){
        
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
        printf("%c\n",aux->Letra.letra);
        ImprimirLP(aux->Letra.Pala);
        aux = aux->prox;
    }

}

//imprime letra dada
void imprimeletradada(lista_letra *lista){
    celula_letra *aux = lista->primeiro->prox;
    char dada;
    printf("Digite a letra que quer imprimir as palavras: ");
    scanf("%c",&dada);
    
    printf("%c\n",dada);
    while (aux->prox != NULL){
        if(dada == aux->Letra.letra){
            printf("%c\n",aux->Letra.letra);
            ImprimirLP(aux->Letra.Pala);
            
        }
        aux = aux->prox;
    }
    printf("\n");
    //printf("%c/n",aux->Letra.letra);
}

//procurar palavra especifica
int ProcurarPalavra(ListaPala *LP, lista_letra *letra, char *pl, char l){
    Apontador aux;
    celula_letra *auxL;
    int result;
    aux = LP->Primeiro->prox;
    auxL = letra->primeiro->prox;
    
    while (auxL != NULL){
        if(auxL->Letra.letra == l){
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
        auxL = auxL->prox;
    }

}

//excluir lista que tenha elemento que o usuario pediu
void ExcluirElemLPEspecifico(ListaPala *LP, lista_letra *letra, char *pl){ //funcao 3
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
void ExcluirElemLPfinal(ListaPala *LP, lista_letra *letra){ //funcao 4
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