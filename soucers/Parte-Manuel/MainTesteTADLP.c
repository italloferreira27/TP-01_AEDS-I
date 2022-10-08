#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADpalavra.h"

int main(){
    ListaPala lista;
    TPalavra obj;

    int escolha, result;
    char palavra[10];

    InstrucoesLP(); //exibe menu de escolhas
    scanf("%d",&escolha);

    InicializarLP(&lista);

    while(escolha != 8){
        switch(escolha){
            case 1:
                printf("Digite uma palavra: ");
                scanf("%s",palavra);
                strcpy(obj.item, palavra);
                InserirElemLP(&lista, obj);//funcao 1
                break;
            case 2:
                printf("Digite uma palavra que queira verificar: ");
                scanf("%s",palavra);
                ProcurarLP(&lista, palavra);//funcao 2
                break;
            case 3:
                printf("Digite a palavra que queria excluir: ");
                scanf("%s",palavra);
                ExcluirElemLPEspecifico(&lista, palavra);
                break;
            case 4:
                printf("Ultima palavra sera excluitda.\n");
                ExcluirElemLPfinal(&lista);
                break;
            case 5:
                printf("Sera exibido a quantidade de palavras existentes.\n");
                printf("%d\n",result = TamanhoLP(lista));
                break; 
            case 6:
                ImprimirLP(&lista);
                break;
            case 7:
                printf("Digite uma palavra para saber em quais linhas ela aparece: ");
                scanf("%s",palavra);
                ImprimirLPespecifica(&lista, palavra);//funcao 7
                break;
            default:
                printf("Escolha invalida.\n\n");
                InstrucoesLP();
                break;
        }
        printf("Escolha uma opcao: ");
        scanf("%d",&escolha);
    }
    return 0;
}