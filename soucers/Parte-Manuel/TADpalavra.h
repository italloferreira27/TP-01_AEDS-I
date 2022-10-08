#include <stdio.h>
#include <stdlib.h>

//definindo tipo char
typedef char TIPOpalavra;

//definicao do TAD palavra
typedef struct{
    TIPOpalavra item[10];
}TPalavra;

//definindo apontado para celula
typedef struct celulapalavra *Apontador;

//definindo a celula do TAD palavra
typedef struct celulapalavra{
    TPalavra palavra;
    struct celulapalavra *prox;
}celulapalavra; //Celula da palavra

//definindo Lista de palavra
typedef struct{
    Apontador Primeiro;
    Apontador Ulitmo;
    int nroElem; //numero de elementos
}ListaPala; //Lista palavra

//Prototipos
int ListaVaziaLP(ListaPala *LP);
void InicializarLP(ListaPala *LP);
void InserirElemLP(ListaPala *LP, TPalavra item); //funcao 1
void ExcluirElemLPfinal(ListaPala *LP); //funcao 4 
void ExcluirElemLPEspecifico(ListaPala *LP, char *pl); //funcao 3 
int ProcurarLP(ListaPala *LP, char *pl); //funcao 2
int TamanhoLP(ListaPala LP); //funcao 8
void ImprimirLP(ListaPala *LP); //funcao 6
void ImprimirLPespecifica(ListaPala *LP, char *pl);//funcao 7
void InstrucoesLP(void); //lista de comandos que sera exibida para o usuario
