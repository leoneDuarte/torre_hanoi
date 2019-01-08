#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int disco;//variavel  que recebe o valor doo disco
}ItemPilha;

typedef struct Celula *Apontador;//tipo apontado que recebe o endere�o do topo e da base

typedef struct Celula{//estrutura que cotrola a cada celula da pilha
	ItemPilha Pitem;
	Apontador prox, ant;
}CelulaPilha;

typedef struct {
	Apontador topo, base;//estrutura que controla a pilha como todo usando o topo a base e o tamanho
	int tamanho;
}ControlePilha;

void CriaPilhaVazia(ControlePilha *Cpilha);//fun��o que cria pilha vazia recebendo a variavel pilha

int PilhaEstaVazia(ControlePilha Cpilha);//fun��o que verifica se apilha esta vazia

int InsereNaPilha(ControlePilha *Cpilha, ItemPilha x);//fun��o insere na pilha usando as variaveis do tipo cpilha e o item disco a ser inserido

int PilhaEstaCheia(ControlePilha Cpilha);//fu��o que verifica se apilha esta cheia

int RetiraDaPilha(ControlePilha *Cpilha);//fun��o que remove o topo da pilha

void ImprimePilha(ControlePilha Cpilha1,ControlePilha Cpilha2,ControlePilha Cpilha3);//imprimindo as 3 pilhas juntas

