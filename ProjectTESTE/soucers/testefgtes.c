#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
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
    
    fclose(file);
    return 0;
}
//verificar se a linha ja foi inserida
//verificar se a palavra ja existe