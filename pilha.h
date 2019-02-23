#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int disco;//variavel  que recebe o valor doo disco
}ItemPilha;

typedef struct Celula *Apontador;//tipo apontado que recebe o endereço do topo e da base

typedef struct Celula{//estrutura que cotrola a cada celula da pilha
	ItemPilha Pitem;
	Apontador prox, ant;
}CelulaPilha;

typedef struct {
	Apontador topo, base;//estrutura que controla a pilha como todo usando o topo a base e o tamanho
	int tamanho;
}ControlePilha;

void CriaPilhaVazia(ControlePilha *Cpilha);//função que cria pilha vazia recebendo a variavel pilha

int PilhaEstaVazia(ControlePilha Cpilha);//função que verifica se apilha esta vazia

int InsereNaPilha(ControlePilha *Cpilha, ItemPilha x);//função insere na pilha usando as variaveis do tipo cpilha e o item disco a ser inserido

int PilhaEstaCheia(ControlePilha Cpilha);//fução que verifica se apilha esta cheia

int RetiraDaPilha(ControlePilha *Cpilha);//função que remove o topo da pilha

void ImprimePilha(ControlePilha Cpilha1,ControlePilha Cpilha2,ControlePilha Cpilha3);//imprimindo  3 pilhas juntas

