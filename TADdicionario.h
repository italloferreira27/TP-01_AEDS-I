#include <stdio.h>
#include <stdlib.h>

//criando a estruta dicionario
typedef struct dicionario{
    char palavras;
    struct palavra *proximo;
}dicionario;

typedef struct(
    palavra *inicio;
    int tam;
)Lista;

void inicializar()