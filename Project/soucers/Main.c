#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/TADpalavra.h"
#include "../headers/TADdicionario.h"

int main(){
    ListaPala lista;
    TPalavra obj;
    lista_letra letras;
    lista_letra *letr;
    letra let;

    int escolha, result;
    char palavra[50];
    char l;

    celula_letra *auxptr;
    celula_letra *aux1;

    FILE *TXTptr;
    TXTptr = fopen("texto.txt", "r");

    InstrucoesLP(); //exibe menu de escolhas
    scanf("%d",&escolha);

    inicia_lista_lista_letra(&letras);


    while(escolha != 9){
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
                        let.letra = palavra[0];
                        verifica_letra(&letras, let, palavra);
                    }
                }
                fclose(TXTptr);
                printf("Leitura realizada com sucesso.\n");
                break;
            case 2:
                printf("Digite uma palavra que queira verificar: ");
                scanf("%s",palavra);
                l = palavra[0];
                result = ProcurarPalavra(letras.primeiro->prox->Letra.Pala, &letras, palavra, l); //funcao 2
                if(result == 1){
                    printf("Palavra existe.\n");
                }
                else{
                    printf("Palavra nao existe.\n");
                }
                break;
            //arrumar
            case 3:
                printf("Digite a palavra que queria excluir: ");
                scanf("%s",palavra);
                //ExcluirElemLPEspecifico(&lista, palavra);
                break;
            //arrumar
            case 4:
                printf("Digite a letra no qual sera removido a ultima palavra: ");
                scanf("%c",&l);
                printf("Ultima palavra sera excluida.\n");
                auxptr = letr->primeiro;
                while(auxptr->prox != NULL){
                    if(auxptr->prox->Letra.letra == l){
                        ExcluirElemLPfinal(auxptr->Letra.Pala, &letras);
                    }
                    auxptr = auxptr->prox;
                }
                break;
            //arrumar
            case 5:
                printf("Sera exibido a quantidade de palavras existentes.\n");
                //printf("%d\n",TamanhoLP(auxptr->Letra.Pala));
                break; 
            case 6:
                imprimeletra(&letras);
                break;
            //arrumar
            case 7:
                printf("Digite uma palavra para saber em quais linhas ela aparece: ");
                scanf("%s",palavra);
                //ImprimirLPespecifica(&lista, &letras, palavra);//funcao 7
                break;
            case 8:
                imprimeletradada(&letras);
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