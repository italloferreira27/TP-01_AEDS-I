#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Project/headers/TADdicionario.h"
#include "../Project/headers/TADpalavra.h"
#include "../Project/headers/TADlinha.h"

int main(){
    lista_letra letras;
    lista_letra *letr;
    letra let;
    ListaPala lista;
    TPalavra obj;

    Tlista linha;
    Titem item;

    int escolha, result;
    int cont = 1;
    
    char linha_texto[100],pala[10];
    char *palavra;
    char l;

    celula_letra *auxptr;
    celula_letra *aux1;

    FILE *TXTptr;
    TXTptr = fopen("texto.txt", "r");


    inicia_lista_lista_letra(&letras);


    while(escolha != 9){

        InstrucoesLP(); //exibe menu de escolhas
        printf("Escolha uma opcao: ");
        scanf("%d",&escolha);
        printf("\n");

        switch(escolha){
            case 1:
                printf("Lendo arquivo de texto.\n\n");
                printf("...\n\n");
                if(TXTptr == NULL){
                    printf("Arquivo nao pode ser aberto.\n");
                    exit (0);
                }
                else{
                   while(fgets(linha_texto, 100, TXTptr) != NULL){
                        palavra = strtok(linha_texto, " "); //Esta separando cada palavra da linha

                        while(palavra){
                            let.letra = palavra[0];
                            //item.chave = cont;
                            verifica_letra(&letras, let, palavra,cont);
                            palavra = strtok(NULL, " "); //Passa para a proxima palavra
                            
                        }
                        cont++;
                    }
                }
                fclose(TXTptr);
                printf("Leitura realizada com sucesso.\n\n");
                break;
            case 2:

                printf("digite a palavra para verificar :");
                scanf("%s",pala);

                trasport(&letras,pala,escolha);
               
                break;
            
            case 3:

                printf("Digite a palavra que queria excluir: ");
                scanf("%s",pala);
                trasport(&letras,pala,escolha); 

                break;

            case 4:

                printf("Digite a letra no qual sera removido a ultima palavra: ");
                scanf("%s",pala);
                printf("Ultima palavra sera excluida.\n");
                trasport(&letras,pala,escolha);

                break;

            case 5:

                printf("Sera exibido a quantidade de palavras existentes na lista da letra: ");
                scanf("%s",pala);
                trasport(&letras,pala,escolha);

                break; 

            case 6:
                imprimeletra(&letras);

                break;

            case 7:

                printf("Digite uma palavra para saber em quais linhas ela aparece: ");
                scanf("%s",pala);
                trasport(&letras,pala,escolha);

                break;

            case 8:

                imprimeletradada(&letras);

                break;

            case 9:

                printf("finalizando ...\n");

                break;

            default:

                printf("Escolha invalida.\n\n");

                break;
        }

    }
    return 0;
}