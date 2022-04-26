#include <bits/stdc++.h>

#define N 112345

using namespace std;

int st[4*N]; ///array da seg Tree
int arr[N]; ///array de dados do problema

int n,q;
int o,a,b,k;

/**função que constroi uma arvore*/
void build(int i,int l,int r){
	if(l==r) //se estamos em uma folha
		st[i] = arr[l];
	else{
		int m = (l+r)/2;

		build(2*i,l,m); //construindo a sub arvore da direita
		build(2*i+1,m+1,r); //construindo a sub arvore da esquerda

		//st[i]=st[2*i]+st[2*i+1]; 
	}
}

/** função que faz uma consulta na arvore*/
int query(int i, int l, int r, int pos){
	if(l==r)
		return st[i];
	else{
		int m = (l+r)/2;

		if(pos<=m)return st[i]+query(2*i,l,m,pos);
		else return st[i]+query(2*i+1,m+1,r,pos);
		//st[i] = st[2*i]+st[2*i+1];
	}
}

/** função que atualiza um segmento na arvore*/
void update(int i, int l, int r, int ql, int qr,int q){
	if(qr<l||r<ql)return;
	if(ql<=l&&r<=qr){
		st[i]+=q;
		return;
	}

	int m=(l+r)/2;
	update(2*i,l,m,ql,qr,q);
	update(2*i+1,m+1,r,ql,qr,q);
}

int main(void){
	int a[6]={0,0,0,0,0,0};
	build(1,1,5);
	for(int i=1;i<=12;i++){
		printf("%d ",st[i]);
	}printf("\n");
	update(1,1,5,1,2,1);
	update(1,1,5,3,5,3);
	for(int i=1;i<=5;i++){
		int r = query(1,1,5,i);
		printf("%d ",r);
	}printf("\n");
}

