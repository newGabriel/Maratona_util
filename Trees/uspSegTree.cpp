#include <bits/stdc++.h>

#define N 112345

using namespace std;

int st[4*N]; ///array da seg Tree
int arr[N]; ///array de dados do problema

int n,q;
int o,a,b,k;

void build(int i,int l,int r){
	if(l==r) //se estamos em uma folha
		st[i] = arr[l];
	else{
		int m = (l+r)/2;

		build(2*i,l,m); //construindo a sub arvore da direita
		build(2*i+1,m+1,r); //construindo a sub arvore da esquerda

		st[i]=st[2*i]+st[2*i+1]; 
	}
}

void update(int i, int l, int r, int pos, int k){
	if(l==r)
		st[i] += k;
	else{
		int m = (l+r)/2;

		if(pos<=m)update(2*i,l,m,pos,k);
		else update(2*i+1,m+1,r,pos,k);

		st[i] = st[2*i]+st[2*i+1];
	}
}

int query(int i, int l, int r, int ql, int qr){
	if(qr<l||r<ql)return 0;
	if(ql<=l&&r<=qr)return st[i];

	int m=(l+r)/2;
	return query(2*i,l,m,ql,qr)+query(2*i+1,m+1,r,ql,qr);
}

int main(void){


}

