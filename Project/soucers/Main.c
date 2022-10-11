#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADpalavra.h"
#include "../headers/TADdicionario.h"

int main(){
    ListaPala lista;
    TPalavra obj;
    lista_letra letras;
    letra let;

    int escolha, result;
    char palavra[50];
    char l;

    FILE *TXTptr;
    TXTptr = fopen("texto.txt", "r");

    InstrucoesLP(); //exibe menu de escolhas
    scanf("%d",&escolha);

    inicia_lista_lista_letra(&letras, &lista);

    while(escolha != 10){
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
                        InserirElemLP(&lista, obj, palavra);//funcao 1
                    }
                }
                fclose(TXTptr);
                printf("Leitura realizada com sucesso.\n");
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
            case 8:
                printf("Inserir letra: ");
                scanf("%s",&l);
                let.letra = l;
                result = verifica_letra(&letras, let);
                if(result == 1){
                    printf("letra nao inserida.\n");
                }
                else{
                    printf("letra inserida.\n");
                }
                break;
            case 9:
                printf("Imprimir letra.\n");
                imprimeletra(&letras);
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
/*
 char linha[100]; //Recebe as frases do texto
    char *palavra; //Lê cada palavra da linha
    int cont = 1; //conta o numero da linha em que a palavra esta
    FILE *file;
    file = fopen("texto.txt", "r");
    if(file == NULL){ //Verificando se encontrou algum arquivo
        printf("Nao foi possivel encontrar o arquivo.");
        return 0;
    }
    while(fgets(linha, 100, file) != NULL){
        palavra = strtok(linha, " "); //Esta separando cada palavra da linha
        while(palavra){
            printf("%s\n", palavra);
            palavra = strtok(NULL, " "); //Passa para a proxima palavra
        }
        printf("LINHA: %d\n", cont);
        cont++;
    }
    
    fclose(file); '\0'
    */