#include <iostream>
#include <stdio.h>

#define N 1123456		///Número maximo de nodes na arvore de suffixos
#define INF 1000000005	///Constante infinito

using namespace std;

string a;		///string de entrada
int t[N][26],	///array de transições
	l[N],		///nós da esquerda
	r[N],		///nós da direita
	p[N],		///nós pai
	s[N],		///suffix link
	tv,			///nó do suffix atual
	tp,			///
	ts,			///Número de nós
	la;			///Caracter atual da string

void ukkadd(int c){
	suff:;
	if(r[tv]<tp){
		if(t[tv][c]==-1){
			t[tv][c]=ts;
			l[ts]=la;
			p[ts++]=tv;
			tv=s[tv];
			tp=r[tv]+1;
			goto suff;
		}
		tv=t[tv][c];
		tp=l[tv];
	}
	if(tp==-1||c==a[tp]-'a')tp++;
	else{
		l[ts]=l[tv];
		r[ts]=tp-1;
		p[ts]=p[tv];
		t[ts][a[tp]-'a']=tv;
		t[ts][c]=ts+1;
		l[ts+1]=la;
		p[ts+1]=ts;
		l[tv]=tp;
		p[tv]=ts;
		t[p[ts]][a[l[ts]]-'a']=ts;
		ts+=2;
		tv=s[p[ts-2]];
		tp=l[ts-2];
		while(tp<=r[ts-2]){
			tv=t[tv][a[tp]-'a'];
			tp+=r[tv]-l[tv]+1;
		}
		if(tp==r[ts-2]+1)s[ts-2]=tv;
		else s[ts-2]=ts;
		tp=r[tv]-(tp-r[ts-2])+2;
		goto suff;
	}
}

void build(){
	ts=2;
	tv=0;
	tp=0;
	fill(r,r+N,(int)a.size()-1);
	s[0]=1;
	l[0]=-1;
	r[0]=-1;
	l[1]=-1;
	r[1]=-1;
	memset(t,-1,sizeof(t));
	fill(t[1],t[1]+26,0);
	for(la=0;la<(int)a.size();++la)ukkadd(a[la]-'a');
}

