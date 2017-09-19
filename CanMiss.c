#include <stdio.h>
#include <stdlib.h>

int dps(int pos,int tabela[32][4]){ //algoritmo de busca em profundidade 
	int tabela2[32][4]; 
	int i;
	int j;
	int pos2;
	for (i=0;i<32;i++){
		for (j=0;j<4;j++){
			tabela2[i][j] = tabela[i][j];
		}
	}
	for (i = 0;i<5;i++){
		printf ("ESTOU NA POSICAO %d ",pos);  //estrutura para verificar qual posicao se encontra
		if (tabela[pos][3] == 1){
			printf ("e sou invalido\n"); //verificacao se a posicao eh invalida (mais canibais do que missionarios de um lado)
			return 1;
		}else if(tabela[pos][3] == 2){
			printf ("- jah passaram por mim \n"); //verificacao se a posicao ja foi visitada 
			return 2;
		}if (i == 0 && tabela[pos][2] == 0){
			pos2 = pos -2 + 16;//Move 2 canibais a direita
		}else if (i == 0 && tabela[pos][2] == 1){
			pos2 = pos +2 - 16;//Move 2 canibais a esquerda
		}else if(i == 1 && tabela[pos][2] == 0){
			pos2 = pos -1 + 16;//Move 1 canibais a direita
		}else if(i == 1 && tabela[pos][2] == 1){
			pos2 = pos +1 - 16;//Move 1 canibais a esquerda
		}else if(i == 2 && tabela[pos][2] == 0){
			pos2 = pos - 5 + 16;//Move 1 canibal e 1 missionario a direita
		}else if(i == 2 && tabela[pos][2] == 1){
			pos2 = pos + 5 - 16 ;//Move 1 canibal e 1 missionario a esquerda
		}else if(i == 3 && tabela[pos][2] == 0){
			pos2 = pos -4 + 16;//Move 1 missionario a direita
		}else if(i == 3 && tabela[pos][2] == 1){
			pos2 = pos + 4 - 16;//Move 1 missionario a esquerda
		}else if(i == 4 && tabela[pos][2] == 0){
			pos2 = pos - 8 + 16;//Move 2 missionario a direita
		}else if(i == 4 && tabela[pos][2] == 1){
			pos2 = pos +8 - 16;//Move 2 missionario a esquerda
		}
		if (pos2 < 0 && pos2 > 31){
			printf("e sou invalido\n");
			return 1;
		}
		tabela2[pos][3] = 2;
		printf ("estou indo para posição %d \n", pos2);
		if (pos2 == 16){
			printf("SOU O RESULTADO FINAL \n"); //resultado final obtido
			return 0;
		}
		j = dps(pos2,tabela2);
		if (j == 0){
			return 0;
		}
		tabela2[pos][3] = 0;
	}
	return 1;
}

int main() {
	int k = 3,j=4,i;
	int vetor[32][4];

	//Preenchendo tabela
	for (i = 0;i<32;i++){

		if (i < 32/2)
			vetor[i][2] = 0;
		else
			vetor[i][2] = 1;
		if (k == 3){
			if (j == 0)	j = 3;
			else j--;
			vetor[i][1] = j;
			
		}else{
			vetor[i][1] = j;
		}

		if (k == 0){
			vetor[i][0] = 0;
			k = 3;
		}else{
			vetor[i][0] = k;
			k--;
		}
		vetor[i][3] = 0;

	}
	//Estados invalidos
	vetor[4][3] = 1;
	vetor[6][3] = 1;
	vetor[7][3] = 1;
	vetor[8][3] = 1;
	vetor[9][3] = 1;
	vetor[11][3] = 1;
	vetor[20][3] = 1;
	vetor[22][3] = 1;
	vetor[23][3] = 1;
	vetor[24][3] = 1;
	vetor[25][3] = 1;
	vetor[27][3] = 1;

	//15 é o estado inicial
	i = dps(15,vetor);

	return 0;
}