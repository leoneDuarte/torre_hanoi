#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void CriaPilhaVazia(ControlePilha *Cpilha) {
	Cpilha = malloc(sizeof(ControlePilha));//malocando espaço na memoria para pilha
	Cpilha->base = NULL;//declarando topo null
	Cpilha->topo = NULL;//base null
}

int PilhaEstaVazia(ControlePilha Cpilha) {
	return !Cpilha.tamanho;//
}

int InsereNaPilha(ControlePilha *Cpilha, ItemPilha x) {
	Apontador aux, aux2;
	if((aux = malloc(sizeof(CelulaPilha)))==NULL) {
       return 0;
   }
	
	if(PilhaEstaVazia(*Cpilha)) {
		Cpilha->base 		= aux;
		Cpilha->topo 		= Cpilha->base;
		Cpilha->topo->ant 	= NULL;
	}

	else{
	
		Cpilha->topo->prox		= aux;
		aux2 					= Cpilha->topo;
		Cpilha->topo			= aux;
		Cpilha->topo->prox		= NULL;
		Cpilha->topo->ant		= aux2;
		
	}

	Cpilha->topo->Pitem		= x;
	Cpilha->topo->prox		= NULL;
	return 1;
	
}

int PilhaEstaCheia(ControlePilha Cpilha) {
	if(Cpilha.tamanho >= 999) {
		printf("\nLimite atingido!!");
		return 1;
	}
	
}

int RetiraDaPilha(ControlePilha *Cpilha) {
	Apontador aux,aux2;
	if(Cpilha->tamanho == 0) {
		printf("\nImpossivel retirar!!");
		printf("\nA Pilha esta vazia!!\n\n");
		system("pause");
		return 0;
	}
	if(Cpilha->tamanho == 1) {		//caso so um item tenha sido innserido na pilha
		Cpilha->topo        	= NULL;	
		Cpilha->tamanho--;
		free(aux2);	
	}
	else{
		aux	= Cpilha->topo;
		Cpilha->topo->ant->prox		= NULL;
		Cpilha->topo 			= Cpilha->topo->ant;
		Cpilha->tamanho--;
		free(aux);
	}
	
	return 1;
}

void ImprimePilha(ControlePilha Cpilha1, ControlePilha Cpilha2, ControlePilha Cpilha3) {
	Apontador aux1,aux2,aux3;
	if(Cpilha1.tamanho == 0 && Cpilha2.tamanho == 0 && Cpilha3.tamanho == 0) {
		printf("\nImpossivel imprimir!!");
		printf("\nA Pilha esta vazia!!\n\n");
		system("pause");
		exit(1);
	}
	else{
		aux1 = Cpilha1.topo;
		aux2 = Cpilha2.topo;
		aux3 = Cpilha3.topo;
		
		printf("Pilha [1]\tPilha [2]\tPilha [3]");
		while(aux1 != NULL) {
			printf("\n\n->%d<-\t",   aux1->Pitem.disco);
			aux1 = aux1->ant;
		}
	
		
		while(aux2 != NULL) {
			printf("\n\t\t->%d<-\t\t", aux2->Pitem.disco);
			aux2 = aux2->ant;
		}
		
		while(aux3 != NULL) {
			printf("\n\t\t\t\t->%d<-\t", aux3->Pitem.disco);
			aux3 = aux3->ant;
		}
		printf("\n\n\n");
		system("pause");
	
	}
}
