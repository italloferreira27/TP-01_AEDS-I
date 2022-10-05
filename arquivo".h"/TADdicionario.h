#include <stdio.h>
#include <stdlib.h>

//criando a estruta dicionario
typedef struct dicionario{
    struct Tadletras *proximo;
    int tam;
}dicionario;

typedef struct{
    Tadletras *inicio;
    Tadletras *proximo;
}Letras;

void inicializarDici(dicionario *dici){


}