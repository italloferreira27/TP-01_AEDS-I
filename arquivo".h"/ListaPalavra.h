#include "Palavra.h"

#ifndef LISTAPALAVRA.H
#define LISTAPALAVRA.H

//lista de palavras ******
typedef struct{
    celulaP *primeiro;
    celulaP *utimo;
    celulaP *anterior;
    int tamanho;
}lista_palavra;

//inicializa lista vazia
void inicializa_listaP(lista_palavra *listP);

//verifica se apalavra ja existe
int palavraex(lista_palavra *list, Tpalavra p);

//adiciona palavra 
void adicionarP(lista_palavra *list,Tpalavra p);

//imprime
void imprime(lista_palavra *list);

//remove palavra(dada a palavra)
void removeP(lista_palavra *list,Tpalavra p);

//remove palavra (final)*****
void retiraP_final(lista_palavra *list);

//retorna tamanho da lista
int gettamanhoListaP(lista_palavra *list);

#endif