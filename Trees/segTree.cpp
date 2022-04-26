/**
@brief codigo que monta uma segtree sem update e faz consultas em rang
*/
#include<stdio.h>
#include<iostream>

#define TAM 100

using namespace std;

int n;
int sT[TAM];

int sum(int a, int b){
	a+=n;
	b+=n;
	int s=0;
	while(a<=b){
		if(a%2==1)s+=st[a++];
		if(b%2==0)s+=st[b--];
		a/=2;
		b/=2;
	}
	return s;
}

void add(int k,int x){
	k+=n;
	sT[k]+=x;
	for(k/=2;k>=1;k/=2){
		sT[k] = sT[2*k]+sT[s*k+1];
	}
}

int main(){

}
