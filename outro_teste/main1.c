#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADpalavra.h"
#include "TADdicionario.h"

int main(){
    letra let;
    lista_letra lista;
    ListaPala pala;
    TPalavra obj;
    char palavra[20];
    int op = 9;
    inicia_lista_lista_letra(&lista);

    //scanf("%s",palavra);
    //letr.letra[0] = palavra[0];
    


    while(op != 0){
        scanf("%d",&op);

        switch(op){
            case 1:
                scanf("%s",palavra);
                let.letra = palavra[0];
                strcpy(obj.item, palavra),
                verifica_letra(&lista,let,palavra);
                break;
            case 2:
                imprimeletra(&lista);
                break;
            case 3:
                imprimeletradada(&lista);
                break;
            case 4:
                
            default:
        }

    }
}