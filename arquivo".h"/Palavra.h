#ifndef PALAVRA.H
#define PALAVRA.H

// Tad linaha //
typedef struct {
    int linha;
}linha;

typedef struct celula_linha{
    linha *linha;
    struct celula_linha *proxL;
}celula_linha;

// Tad palavra //
typedef struct {
    char palavra[20];
    celula_linha *llinha;
}palavra;

void inicializarP(palavra *palavra){
    
}

#endif