#include <stdio.h>
#include <iostream>

#define MAX 1010		// tamanho maximo do  array com sobra

using namespace std;

int n;					// tamanho do array
int bit[MAX];			// Fenwick tree

void add(int k,int x){	// função que adiciona um valor a uma posição da arvore e faz update das dependencias
	while(k<=n){		// enquanto k for menor q n existem updates a serem feitos
		bit[k] += x;	// atualizando valor da dependencia
		k += k&-k;		// usando o bit menos significativo para encontrar a posição das dependencias
	}
}

int sum(int k){			// função que calcula a soma do intervalo [0,k]
	int s=0;			/// variavel que guarda a soma do intervalo
	while(k>=1){		// enquanto k for maior que 1 existem itens a serem somados no intervalo
		s += bit[k];	// soma-se o valor da posição k da arvore no intervalo
		k -= k&-k;		// usando o bit menos significativo para encontrar a proxima posição não somada do intervalo
	}
}

int main(void){
	
	scanf("%d",&n);
	
	memset(bit,0,sizeof(bit));
	
	for(int i=0;i<n;i++){
		int l;
		scanf("%d",&l);
		add(i+1,l);
	}
	
	int q;
	scanf("%d",&q);
	printf("%d\n",sumy(q));

	return 0;
}
