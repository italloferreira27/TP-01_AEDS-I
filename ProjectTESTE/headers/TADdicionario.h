#ifndef TADDICIONARIO_H
#define TADDICIONARIO_H

#include "TADpalavra.h"
#include "TADlinha.h"

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
int verifica_letra(lista_letra *lista, letra l, char *charptr, TPalavra ITEMPALA, Tlista *Lista_linha ,Titem item_linha);

// imprime lista
void imprimeletra(lista_letra *lista, Tlista* Lista_linha);

//imprime letra dada
void imprimeletradada(lista_letra *lista, char l, Tlista* Lista_linha);

//imprime palavra dada
void ProcurarPalavra(lista_letra *letra, char *pl, char l);

//excluir elemento final de uma letra
void ExcluirElemFinal(lista_letra *letra, char l); //funcao 4 

//imprimir palavra especifica
void PalavraEsp(lista_letra *letra, char *pl, char l); //funcao 7

//excluir palavra dada
void ExcluirElemEspecifico(lista_letra *letra, char *pl, char l); //funcao 3 

//tamanho da lista de palavras
void TamanhoLetra(lista_letra *letra, char l);

#endif