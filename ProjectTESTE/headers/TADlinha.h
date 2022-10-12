#ifndef TADlinha_h
#define TADlinha_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int Tipochave;
typedef struct{
    Tipochave chave; 
}Titem;

typedef struct Celula_Linha* Apontado;
typedef struct Celula_Linha{
    Titem linha;
    struct Celula_Linha* prox;
}Celula_Linha;

typedef struct{
    Apontado Primeiro;
    Apontado Ultimo;
}Tlista;

int LL_Vazia(Tlista* lista);
void LL_Inicializa(Tlista* lista);
void LL_Inserir(Tlista* lista, Titem item);
int LL_Imprimir(Tlista* lista);
int LL_Procurar(Tlista* lista, Titem item);
int LL_ExcluirFinal(Tlista* lista);
int LL_ExcluirEspecifico(Tlista* lista, Titem item);

#endif