#include "ListaPalavra.h"
#include "TADdicionario.h"
#include "Palavra.h"
#include <stdio.h>

int main(){
    int op=9,linha;
    Tpalavra P;
    lista_palavra L;

    inicializa_listaP(&L);

    while(op!=0){
        scanf("%d",&op);
        printf("*********\n");
        switch(op){
            case 1:
                scanf("%s",P.palavra);
                adicionarP(&L,P);
                break;
            case 2:
                imprime(&L);
                break;
            case 3:
                retiraP_final(&L);
                break;
            case 4:
                scanf("%s",P.palavra);
                removeP(&L,P);
                break;
            case 0:
                printf("fim");
                break;
            default:

        }
    
    }
}