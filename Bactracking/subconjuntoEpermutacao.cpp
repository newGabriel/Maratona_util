#include <bits/stdc++.h>

using namespace std;

int v[3]={0,0,0};
vector<int> permutation;
bool cv[3];

/** função que printa todos subconjuntos de um conjunto de n*/
void subconjuntos(int k, int n){
	if(k==n){
		printf("{ ");
		for(int i=0;i<n;i++){
			if(v[i]==1){
				printf("%d ",i+1);
			}
		}
		printf("\b} ");
	}
	else{
		v[k]=1;
		subconjuntos(k+1,n);
		v[k]=0;
		subconjuntos(k+1,n);
	}
}

/** função que printa as permutações de um conjunto de n elementos*/
void permutacao(int n){
	if(permutation.size()==n){
		printf("{");
		for(int i=0;i<n;i++){
			if(cv[i]==true){
				printf("%d ",permutation[i]);
			}
		}
		printf("\b} ");
	}
	else{
		for(int i=1;i<=n;i++){
		if(cv[i-1])continue;
		cv[i-1] =true;
		permutation.push_back(i);
		permutacao(n);
		cv[i-1] =false;
		permutation.pop_back();}
	}
}

int main(){
	subconjuntos(0,3);
	//permutacao(3);
	printf("\n");
	return 0;
}
