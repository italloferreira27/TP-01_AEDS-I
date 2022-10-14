#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADpalavra.h"
#include "../headers/TADdicionario.h"

int main(){
    ListaPala lista;
    TPalavra obj;
    lista_letra letras;
    //lista_letra *letr;
    letra let;

    int escolha, result;
    char palavra[50];
    char z[1];
    char l;

    FILE *TXTptr;
    TXTptr = fopen("texto.txt", "r");

    
    scanf("%d",&escolha);

    inicia_lista_lista_letra(&letras);

    while(escolha != 9){
        
        InstrucoesLP(); //exibe menu de escolhas
        
        switch(escolha){
            //funciona
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
                        let.letra = palavra[0];
                        verifica_letra(&letras, let, palavra);
                    }
                }
                fclose(TXTptr);
                printf("Leitura realizada com sucesso.\n");
                break;
            //funciona
            case 2:
                printf("Digite uma palavra que queira verificar: ");
                scanf("%s",palavra);
                l = palavra[0];
                ProcurarPalavra(&letras, palavra, l); //funcao 2
                break;
            //funciona
            case 3:
                printf("Digite a palavra que queria excluir: ");
                scanf("%s",palavra);
                l = palavra[0];
                ExcluirElemEspecifico(&letras, palavra, l);
                break;
            //funciona
            case 4:
                printf("Digite a letra no qual sera removido a ultima palavra: ");
                scanf("%s",z);
                l = z[0];
                printf("Ultima palavra sera excluida.\n");
                ExcluirElemFinal(&letras, l);
                break;
            //funciona
            case 5:
                printf("Digite em qual letra voce quer saber a quantidade de palavra: ");
                scanf("%s",z);
                l = z[0];
                printf("Sera exibido a quantidade de palavras existentes.\n");
                TamanhoLetra(&letras, l);
                break;
            //funciona 
            case 6:
                imprimeletra(&letras);
                break;
            //funciona so nao imprime o ultimo TAD letra
            case 7:
                printf("Digite uma palavra para saber em quais linhas ela aparece: ");
                scanf("%s",palavra);
                l = palavra[0];
                PalavraEsp(&letras, palavra, l);
                break;
            //funciona
            case 8:
                printf("Digite a letra em que queira imprimir as palavras: ");
                scanf("%s",z);
                l = z[0];
                imprimeletradada(&letras, l);
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