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
    } 
}

//verifica se a letra ja exista(chamar para inserir palavra)
int verifica_letra(lista_letra *lista, letra l, char *charptr, TPalavra ITEMPALA, Tlista* Lista_linha ,Titem item_linha){
    celula_letra *inicio = lista->primeiro->prox;
    //printf("%s",palavra);

    int i,cont;
   
    while(inicio != NULL){
        if(inicio->Letra.letra == l.letra){
            
            InserirElemLP(inicio->Letra.Pala, inicio->Letra.Pala->Ulitmo->palavra, charptr, Lista_linha, item_linha);
            return 1;
        }
        inicio = inicio->prox;
    } 
    l.Pala = (ListaPala *)malloc(sizeof(ListaPala));
    //ITEMPALA.linha = (Tlista *)malloc(sizeof(Tlista));
    InicializarLP(l.Pala);
    LL_Inicializa(ITEMPALA.linha);
    //l.palavras->Ulitmo->palavra.item = palavra;
    InserirElemLP(l.Pala,l.Pala->Ulitmo->palavra,charptr, Lista_linha, item_linha);
    insere_letra(lista,l,charptr);
    return 0;
}

// imprime lista
void imprimeletra(lista_letra *lista, Tlista* Lista_linha){
    celula_letra *aux = lista->primeiro->prox;

    while(aux != NULL){
        printf("%c\n",aux->Letra.letra);
        ImprimirLP(aux->Letra.Pala, Lista_linha);
        aux = aux->prox;
    }

}

//imprime letra dada
void imprimeletradada(lista_letra *letra, char l, Tlista* Lista_linha){
    celula_letra *auxptr;

    auxptr = letra->primeiro->prox;

    while(auxptr != NULL){
        if(auxptr->Letra.letra == l){
            ImprimirLP(auxptr->Letra.Pala, Lista_linha);
            return;
        }
        auxptr = auxptr->prox;
    }
    printf("letra nao existe.\n");

}

//procurar palavra especifica
void ProcurarPalavra(lista_letra *letra, char *pl, char l){
    int result;
    celula_letra *auxptr;

    auxptr = letra->primeiro->prox;

    while(auxptr != NULL){
        if(auxptr->Letra.letra == l){
            result = ProcurarLP(auxptr->Letra.Pala, pl);
            if(result == 1){
                    printf("Palavra existe.\n");
            }
            else{
                    printf("Palavra nao existe.\n");
            }
            return;
        }
        auxptr = auxptr->prox;
    }

}

//excluir lista que tenha elemento que o usuario pediu
void ExcluirElemEspecifico(lista_letra *letra, char *pl, char l){ //funcao 3
    celula_letra *auxptr;

    auxptr = letra->primeiro->prox;

    while(auxptr != NULL){
        if(auxptr->Letra.letra == l){
            ExcluirElemLPEspecifico(auxptr->Letra.Pala, pl);
            return;
        }
        auxptr = auxptr->prox;
    }
    printf("letra nao existe.\n");
}

//excluir o ultimo elemento
void ExcluirElemFinal(lista_letra *letra, char l){ //funcao 4
    celula_letra *auxptr;

    auxptr = letra->primeiro->prox;

    while(auxptr != NULL){
        if(auxptr->Letra.letra == l){
            ExcluirElemLPfinal(auxptr->Letra.Pala);
            return;
        }
        auxptr = auxptr->prox;
    }
    printf("letra nao existe.\n");
}

void TamanhoLetra(lista_letra *letra, char l){
    celula_letra *auxptr;

    auxptr = letra->primeiro->prox;

    while(auxptr != NULL){
        if(auxptr->Letra.letra == l){
            printf("%d\n", TamanhoLP(auxptr->Letra.Pala));
            return;
        }
        auxptr = auxptr->prox;
    }
    printf("letra nao existe.\n");
}

void PalavraEsp(lista_letra *letra, char *pl, char l){
    celula_letra *auxptr;

    auxptr = letra->primeiro->prox;

    while(auxptr != NULL){
        if(auxptr->Letra.letra == l){
            ImprimirLPespecifica(auxptr->Letra.Pala, pl);
            return;
        }
        auxptr = auxptr->prox;
    }
    printf("letra nao existe.\n");
}