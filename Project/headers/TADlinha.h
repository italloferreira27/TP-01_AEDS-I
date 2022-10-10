#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int l;
}Tlinha;

typedef struct linha *Apontado;
typedef struct linha{
    Tlinha NumLinha;
    struct linha* prox;
}celula_linha;

typedef struct{
    Apontado Primeiro;
    Apontado Ultimo;
}Lista_Linha;

int LL_vazia(Lista_Linha *linha);
void LL_Inicializa(Lista_Linha* linha);
void LL_Inserir(Lista_Linha* linha, Tlinha* num);
void LL_Imprimir(Lista_Linha* linha);
//void LL_Remove(Lista_Linha* linha, Tlinha* num);