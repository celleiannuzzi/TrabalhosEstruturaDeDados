#include <stdio.h>
#include <stdlib.h>

// Trabalho de Estrutura de Dados - criando a função MergeSort - Marcelle Iannuzzi- DRE 118056472

void merge(int *vetor, int inicio, int meio, int fim){ //função que irá juntar os vetores separados, ordenando-os
	int *temp, pos1, pos2, tamanho, i, j, k; // inicia variáveis utilizadas
	int fim1 = 0, fim2 = 0; //inicia variáveis que serão utilizadas como valores booleanos (0 ou 1)
	tamanho = fim - inicio + 1; //pega o tamanho total do vetor
	pos1 = inicio; // pega posicao inicial
	pos2 = meio+1; // pega posicao final
	temp = (int *) malloc(tamanho * sizeof(int)); //aloca o tamanho do vetor em um vetor temporário auxiliar
	if (temp != NULL){ //verifica se o vetor é nulo
		for (i=0; i< tamanho; i++){ ;//faz um loop do inicio ao fim do vetor
			if(!fim1 && !fim2){ //verifica se já chegou ao final dos dois vetores que estão sendo unidos e ordenados
				if(vetor[pos1] < vetor[pos2]) //verifica qual valor é menor
					temp[i]= vetor[pos1++]; //se a pos1 for menor, aloca ela primeiro no vetor temporário vazio
				else
				temp[i]= vetor[pos2++]; //se a pos2 for menor, aloca ele primeiro no vetor temporário vazio
				
				if(pos1 > meio) //verifica se já chegou no fim do primeiro vetor
					fim1 = 1; //se sim, vai de 0 para 1
					
				if(pos2 > fim) //verifica se já chegou no fim do segundo vetor
					fim2 = 1; //se sim, vai de 0 para 1
					
			} else { //se não chegou ao fim dos dois vetores, verifica qual dos dois ainda falta alocar os valores
				if(!fim1)
					temp[i] = vetor[pos1++];
				else
					temp[i] = vetor[pos2++];
			}
		}
		
		for(j=0, k=inicio; j<tamanho; j++, k++){ //ordena os valores no vetor original que está em ponteiro
			vetor[k] = temp[j];
		}
	}
	free(temp); // libera o espaço na memória do vetor temporário auxiliar
	
}

void mergesort(int *vetor, int inicio, int fim){ //função recursiva para o mergesort
	int meio; //divide o vetor em 2
	if(inicio < fim){ //verifica se já chegou ao ponto de cada vetor ter 1 elemento
		meio = (inicio+fim)/2; //divide o vetor no meio
		mergesort(vetor, inicio, meio); //chama a função recursiva novamente para a primeira parte do vetor divido em 2
		mergesort(vetor, meio+1, fim); //chama a função recursiva novamente para a segunda parte do vetor divido em 2
		merge(vetor, inicio, meio, fim); //chama a função merge que irá juntar os vetores separados enquanto ordena
		//eles em 1 só vetor
	}
}

int main(int argc, char *argv[]) {
	int num;//Variavel que será lida do teclado
	int *vetor; //vetor que irá salvar os números passados
	vetor = (int *) malloc(0 *sizeof(int)); //inicia o vetor como nulo
	int linha = 0; //Começando da linha 0, vamos aumentando para saber a quantidade de linhas
	while (!feof(stdin)){ //while e if sugeridos pelo prof na aula para receber os números
		if (scanf("%d",&num)==1){ //pega o numero digitado			
			vetor = (int *)realloc(vetor, (linha+1)*sizeof(int));//Realoca o tamanho do vetor para caber + um numero 
			vetor[linha]=num; //aloca o número lido na linha atual
			linha++; //aumenta o número de linhas
		}
	}
	
	mergesort(vetor, 0, linha-1);//chama a função que ordena o vetor (mergesort)
	
	for(num=0;num<linha;num++){ //printa o vetor já ordenado, um número por linha
		printf("%d\n", vetor[num]);
	}
}
