#include "./headers/ListaPalavra.h"

int main(){
    int op=9,linha;
    Tpalavra P;
    lista_palavra L;

    inicializa_listaP(&L);

    printf("1 = Adicionar\n2 = imprimir\n3 = retirar\n4 = Remover\n\n");
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