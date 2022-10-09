#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADpalavra.h"
#include "../headers/TADdicionario.h"

int main(){
    ListaPala lista;
    TPalavra obj;
    TlistaL Letras;

    int escolha, result;
    char palavra[50],l;

    FILE *TXTptr;
    TXTptr = fopen("texto.txt", "r");

    InstrucoesLP(); //exibe menu de escolhas
    scanf("%d",&escolha);

    InicializarLP(&lista);
    IniciarDici(&Letras);

    while(escolha != 8){
        switch(escolha){
            case 1:
                printf("Lendo arquivo de texto.\n");
                if(TXTptr == NULL){
                    printf("Arquivo nao pode ser aberto.\n");
                    exit (0);
                }
                else{
                    while (!feof(TXTptr)){
                        fscanf(TXTptr, "%s", palavra);
                        strcpy(obj.item, palavra);
                        //InserirElemLP(&lista, obj, palavra);//funcao 1
                        l = palavra[0];
                        IniciarDici(&Letras, obj);
                    }
                }
                fclose(TXTptr);
                printf("Leitura realizada com sucesso.\n");
                break;
            case 2:
                printf("Digite uma palavra que queira verificar: ");
                scanf("%s",palavra);
                result = ProcurarLP(&lista, palavra);//funcao 2
                if(result == 1){
                    printf("Palavra existe.\n");
                }
                else{
                    printf("Palavra nao existe.\n");
                }
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