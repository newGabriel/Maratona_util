#include <bits/stdc++.h>

using namespace std;

const int N=1000000, ///número maximo de nós na suffixtree
	INF=1000000000; ///Constante Infinito
	
string a; ///string de input para qual a suffix tree estásendo construida
int t[N][26], ///array de transição
	l[N], /// arestas esquerda
	r[N], /// e direita da string
	p[N], /// nó pai
	s[N], /// suffix link
	tv, /// nó do suffix atual
	tp, ///possição da string que corresponde a posição da string
	ts, ///número de nós
	la; ///caracter atual

void ukkadd(int c){ //adiciona caracter à árvore
	suff:; //retornaremos aqui a cada iteração para o sufixo
	if(r[tv]<tp){ //verificando se ainda estamos no limite da aresta
		//se não estamos procuramos um novo nó, se não houver adicionamos uma nova folha
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
	}// em outro caso processamos a proxima aresta
	if(tp==-1||c==a[tp]-'a')
		tp++; //se a letra na aresta for igual a $c$, desça nessa aresta
	else{
		//caso contrario dividimos a aresta com um middle-node 
		l[ts]=l[tv];
		r[ts]=tp-1;
		p[ts]=p[tv];
		t[ts][a[tp]-'a']=tv;
		//adiciona uma folha ts+1. isso corresponde a transição atravez de c
		t[ts][c]=ts+1;
		l[ts+1]=la;
		p[ts+1]=ts;
		//update das informações do nó atual
		l[tv]=tp;
		p[tv]=ts;
		t[p[ts]][a[l[ts]]-'a']=ts;
		ts+=2;
		//$tp$ marca a posição do sufixo atual
		tv=s[p[ts-2]];
		tp=l[ts-2];
		//enquanto o sufixo atual não acabou descemos atravez dele
		while(tp<=r[ts-2]){
			tv=t[tv][a[tp]-'a'];
			tp+=r[tv]-l[tv]+1;
		}
		//se estivermos em um nó, adicione um link de sufixo a ele, caso contrário, adicione o link a $ts$
		//criaremos $ts$ na proxima iteração
		if(tp==r[ts-2]+1)
			s[ts-2]=tv;
		else
			s[ts-2]=ts;
		//adiciona tp à nova aresta e retorna para adicionar letra ao sufixo
	}
}

void build() {
    ts=2;
    tv=0;
    tp=0;
    fill(r,r+N,(int)a.size()-1);
    //inicializar a árvora apartir da raiz
    s[0]=1;
    l[0]=-1;
    r[0]=-1;
    l[1]=-1;
    r[1]=-1;
    memset (t, -1, sizeof t);
    fill(t[1],t[1]+26,0);
    //adicione na árvore o texto letra a letra
    for (la=0; la<(int)a.size(); ++la)
        ukkadd (a[la]-'a');
}

int main(void){
	cin>>a;
	build();
	return 0;
}
