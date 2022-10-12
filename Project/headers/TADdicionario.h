#ifndef TADDICIONARIO_H
#define TADDICIONARIO_H

#include "TADpalavra.h"

//letra
typedef struct {
    char letra;
    ListaPala *Pala;
}letra;

//celula letra
typedef struct celula_letra{
    letra Letra;
    struct celula_letra *prox;
}celula_letra;

//lista de letras
typedef struct{
    celula_letra *primeiro;
    celula_letra *utimo;
}lista_letra;

//inicializa lista de letras
void inicia_lista_lista_letra(lista_letra *lista);

//insere letra na lista
void insere_letra(lista_letra *lista, letra l,char *Palavra);

//verifica se a letra ja exista(chamar para inserir palavra)
int verifica_letra(lista_letra *lista, letra l, char *charptr);

// imprime lista
void imprimeletra(lista_letra *lista);

//imprime letra dada
void imprimeletradada(lista_letra *lista);

//imprime palavra dada
int ProcurarPalavra(ListaPala *LP, lista_letra *letra, char *pl, char);

//excluir elemento final de uma letra
void ExcluirElemLPfinal(ListaPala *LP, lista_letra *letra); //funcao 4 

//excluir palavra dada
void ExcluirElemLPEspecifico(ListaPala *LP, lista_letra *letra, char *pl); //funcao 3 

#endif