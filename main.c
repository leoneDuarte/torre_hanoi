/* torre de hanoi 08/11/2017
leone duarte de oliveira
italo rodirgues
charlys machado  */



#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

main(){
	
	int escolha,menu,menu2,sair=0,num_discos,i=0,compara1,compara2,contador=0;
	ControlePilha Cpilha1, Cpilha2, Cpilha3;
	
	ItemPilha disco, item, item2;
	
	printf("\nBEM VINDO A TORRE DE HANOI\n");
	printf("\n\tREGRAS \n[1]-O disco 0 e considerado nulo por isso nao conta como disco\n");
	printf("[2]-E proibido colocar um disco maior sobre um menor\n");
	printf("[3]-Vence quem conseguir colocar os discos da mesma forma como estavam na torre 1 na torre 3 \ncom o menor numero de movimentos\n\n");
	CriaPilhaVazia(&Cpilha1);//criando tres pilhas vazias
	CriaPilhaVazia(&Cpilha2);
	CriaPilhaVazia(&Cpilha3);
	
	Cpilha1.tamanho = 0;
	Cpilha2.tamanho = 0;//zerando o tamanho
	Cpilha3.tamanho = 0;
	
	disco.disco = 0;//iserindo um valo nulo quue nao servira como disco
	InsereNaPilha(&Cpilha1, disco);	
	InsereNaPilha(&Cpilha2, disco);//inserindo esse valor nos tres discos
	InsereNaPilha(&Cpilha3, disco);	
	
	Cpilha1.tamanho ++;
	Cpilha2.tamanho ++;//aumentando o tmanho nos tres discos
	Cpilha3.tamanho ++;
	
	printf("Indique a quantidade de discos que o jogo deve usar: ");//usuario insere o numero de discos
	scanf("%d",&num_discos);
	system("cls");
	
	printf("\n\nQuantidade de discos escolhidas: %d\n\n",num_discos);
	
	printf("OBS: Para melhor jogabilidade, recomenda-se o uso da TELA CHEIA \n\n\n");
	system("pause");
	system("cls");
	
			
	if(num_discos > 64 || num_discos < 4){
		printf("ATENÇÃO: ");
		printf("Quantidade de discos nao permitido, digite novamente!\n\n");
		system("pause");
		return 0;
			
		}
	

	i = num_discos;
	 
	while(i > 0 ){		//inserindo os discos na torre numero 1
		disco.disco=i;
		InsereNaPilha(&Cpilha1, disco);
		Cpilha1.tamanho++;
		i--;
	}
	
	while(sair == 0){
		ImprimePilha(Cpilha1, Cpilha2, Cpilha3);	//pilha que sera exibida para o usuario
		printf("\n\n\n\t\t--ESCOLHA UM MOVIMENTO--");
		printf("\n[1]-PILHA 1 > PILHA 2 \n\n [2]-PILHA 1 > PILHA3");
		printf("\n\n[3]-PILHA 2 > PILHA 1\n\n[4]-PILHA 2 > PILHA 3");
		printf("\n\n[5]-PILHA 3 > PILHA 1 \n\n[6]-PILHA 3 > PILHA 2\n\n");
		printf("---------------");
		printf("\nOutras Opcoes");
		printf("\n---------------");
		printf("\n[7]-Regras do jogo\n[8]Sair do jogo \n-->");
		scanf("%d",&menu);//menu de escolha para o usuario com as possibilidades de jogada
		system("cls");
		switch(menu){
			
			case 1:		
				item = Cpilha1.topo->Pitem;  //pegando o topo das torres 1 e 2 que serao usadas nessa jogada
				item2 = Cpilha2.topo->Pitem;
								
								
								
				if(Cpilha1.tamanho == 1){//caso o tamanho seja 1 ou seja caso so tenha o numeo 0 la ele nao podera retirar
					printf("esta pilha esta vazia impossivel retirar\n");
					break;
				}
				if(item.disco > item2.disco && Cpilha2.tamanho > 1){//caso o disco debaixo seja menor que o de cima
					printf("\njogada invalida pois o disco abaixo e menor ou a pilha esta vazia\n");
					system("pause");
					break;
				}
				
				
				
				RetiraDaPilha(&Cpilha1);	//retira o topo da pilha 1			
				InsereNaPilha(&Cpilha2, item);//insere na pilha de destino
				Cpilha2.tamanho++;	//aumenta o tamanho
				contador++;//contando o numero de movimentos
				system("cls");			
				break;	
				
				
							
			case 2:
				item = Cpilha1.topo->Pitem;//coletando o topo da pilha de saida
				item2 = Cpilha3.topo->Pitem;//coletando o topo da pilha que ira receber o novo topo
				
				
				if(Cpilha1.tamanho == 1){//caso o tamanho seja 1 ou seja caso so tenha o numeo 0 la ele nao podera retirar
					printf("esta pilha esta vazia impossivel retirar\n");
					break;
				}				
				
				
				if(item.disco > item2.disco && Cpilha3.tamanho > 1 || Cpilha1.tamanho == 0){   //verificando se o debaixo e maior ou menor que o disco de cima
					printf("\njogada invalida pois o disco abaixo e menor ou a pilha que deseja retirar esta vazia\n");
					system("pause");
					break;
				}
				
				RetiraDaPilha(&Cpilha1);//removendo o item da torre escolhida	
				InsereNaPilha(&Cpilha3, item);//insere na pilha de destino
				Cpilha3.tamanho++;
				contador++;	//contando o numero de movimentos
				if(Cpilha3.tamanho == num_discos + 1){//verificando se ha um vencedor caso haja o mesmo numero de discos na torre 3 e os que foram inseridos pelo usuario
					system("cls");					
					ImprimePilha(Cpilha1, Cpilha2, Cpilha3);	
					printf("\n\n\t\t\tvoce venceu!!!!");
					sair++;
					break;
				}
				
				system("cls");
				break;
				
				
			case 3:		
				item = Cpilha2.topo->Pitem;
				item2 = Cpilha1.topo->Pitem;	//pegando o topo das torres 1 e 2 que serao usadas nessa jogada
				
				
				if(Cpilha2.tamanho == 1){//caso o tamanho seja 1 ou seja caso so tenha o numeo 0 la ele nao podera retirar
					printf("esta pilha esta vazia impossivel retirar\n");
					system("pause");
					break;
				}
							
							
				if(item.disco > item2.disco && Cpilha1.tamanho > 1){ //verificando se o debaixo e maior ou menor que o disco de cima
					printf("\njogada invalida pois o disco abaixo e menor\n");
					system("pause");
					break;
				}
				
				RetiraDaPilha(&Cpilha2);//removendo o item da torre escolhida
				InsereNaPilha(&Cpilha1, item);//insere na pilha de destino
				Cpilha1.tamanho++;	
				contador++;//contando o numero de movimentos
				system("cls");			
				break;		
					
			case 4:
				item = Cpilha2.topo->Pitem;
				item2 = Cpilha3.topo->Pitem;	//pegando o topo das torres 1 e 2 que serao usadas nessa jogada
				
				
				if(Cpilha2.tamanho == 1){//caso o tamanho seja 1 ou seja caso so tenha o numeo 0 la ele nao podera retirar
					printf("esta pilha esta vazia impossivel retirar\n");
					system("pause");
					break;
				}			
				
				if(item.disco > item2.disco && Cpilha3.tamanho > 1 ){ //verificando se o debaixo e maior ou menor que o disco de cima
					printf("\njogada invalida pois o disco abaixo e menor\n");
					system("pause");
					break;
				}
				
				RetiraDaPilha(&Cpilha2);//removendo o item da torre escolhida
				InsereNaPilha(&Cpilha3, item);//insere na pilha de destino
				Cpilha3.tamanho++;	
				contador++;//contando o numero de movimentos
				
				if(Cpilha3.tamanho == num_discos + 1){//verificando se ha um vencedor caso haja o mesmo numero de discos na torre 3 e os que foram inseridos pelo usuario
					system("cls");					
					ImprimePilha(Cpilha1, Cpilha2, Cpilha3);	
					printf("\n\n\t\t\tvoce venceu!!!!");
					printf("\n numero de movimentos: %d",contador);
					sair++;
					break;
				}
				
				system("cls");			
				break;	
				
			case 5:
				item = Cpilha3.topo->Pitem;//pegando o topo das torres 1 e 2 que serao usadas nessa jogada
				item2 = Cpilha1.topo->Pitem;
				
				
				if(Cpilha3.tamanho == 1){//caso o tamanho seja 1 ou seja caso so tenha o numeo 0 la ele nao podera retirar
					printf("Esta pilha esta vazia impossivel retirar\n");
					system("pause");
					break;
				}				
				
				if(item.disco > item2.disco && Cpilha1.tamanho > 1){
					printf("\njogada invalida pois o disco abaixo e menor\n");
					system("pause");
					break;
				}
				
				RetiraDaPilha(&Cpilha3);//removendo o item da torre escolhida
				InsereNaPilha(&Cpilha1, item);//insere na pilha de destino
				Cpilha1.tamanho++;	
				contador++;//contando o numero de movimentos
				system("cls");			
				break;	
				
				
			case 6:
				item = Cpilha3.topo->Pitem;//pegando o topo das torres 1 e 2 que serao usadas nessa jogada
				item2 = Cpilha2.topo->Pitem;
				
				if(Cpilha3.tamanho == 1){//caso o tamanho seja 1 ou seja caso so tenha o numeo 0 la ele nao podera retirar
					printf("esta pilha esta vazia impossivel retirar\n");
					system("pause");
					break;
				}	
							
				if(item.disco > item2.disco && Cpilha2.tamanho > 1){ //verificando se o debaixo e maior ou menor que o disco de cima
					printf("\nJogada invalida pois o disco abaixo e menor\n");
					system("pause");
					break;
				}
				
				RetiraDaPilha(&Cpilha3);//removendo o item da torre escolhida
				InsereNaPilha(&Cpilha2, item);//insere na pilha de destino
				Cpilha2.tamanho++;
				contador++;	//contando o numero de movimentos
				system("cls");			
				break;	
				
			case 7:
				printf("\nREGRAS \n [1]-O disco 0 e considerado nulo por isso na conta como disco\n[2]-e proibido colocar um disco maior sobre um menor");	
				printf("\n[3]-vence quem conseguir colocar os discos da mesma forma como estavam na torre 1 na torre 3\ncom o menor numero de movimentos\n\n\n\n\n\n");		
				system("pause");
				break;
				
				
			case 8:
				printf("O Jogo foi encerrado");
				sair++;
				
		}
	}
}

						
				
				
	
