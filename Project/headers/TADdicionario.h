#ifndef TADDICIONARIO_H
#define TADDICIONARIO_H

//letra
typedef struct {
    char letra[2];
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
void insere_letra(lista_letra *lista, letra l);

//verifica se a letra ja exista(chamar para inserir palavra)
int verifica_letra(lista_letra *lista, letra l);

// imprime lista
void imprimeletra(lista_letra *lista);

#endif