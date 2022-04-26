/**
@brief crivo de erastotenes
*/
#include <iostream>

#define N 1000010

using namespace std;

bool composto[N]; //memo para salvar os supostos números primos

void crivo(int n){ //crivo de erastotenes pre-processamento de números primos
	composto[1]=1;
	for(int i=2;i<=n;i++){
		if(!composto[i]){
			for(int j=2;j*i<=n;j++){
				composto[i*j]=1;
			}
		}
	}
	return;
}

int main(){
	crivo(60);
	for(int i=2;i<60;i++){
		if(composto[i]==0)printf("%d ",i);
	}
	puts("");
}
