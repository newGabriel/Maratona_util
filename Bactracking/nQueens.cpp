#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

set<pair<int,int>> queens;

/**Função que verifica se existe alguma rainha atacada*/
bool ataca(int q1x,int q1y,int q2x,int q2y,int tam){
	if(q1x==q2x)return true;
	if(q1y==q2y)return true;
	for(int i=0;;i++){
		if(q1x+i>=tam)break;
		if(q1y+i>=tam)break;
		if(q1x+i==q2x&&q1y+i==q2y)return true;
	}
	for(int i=0;;i++){
		if(q1x-i<0)break;
		if(q1y-i<0)break;
		if(q1x-i==q2x&&q1y-i==q2y)return true;
	}
	for(int i=0;;i++){
		if(q1x+i>=tam)break;
		if(q1y-i<0)break;
		if(q1x+i==q2x&&q1y-i==q2y)return true;
	}
	for(int i=0;;i++){
		if(q1x-i<0)break;
		if(q1y+i>=tam)break;
		if(q1x-i==q2x&&q1y+i==q2y)return true;
	}
	return false;
}

/**Backtracking que calcula a posição das rainhas*/
bool nQueens(int tam,int col){
	if(col==tam)return true;
	for(int i=0;i<tam;i++){
		bool t;
		for(auto j : queens){
			t = ataca(col,i,j.first,j.second,tam);
			if(t)break;
		}
		if(t)continue;
		queens.insert({col,i});
		t = nQueens(tam,col+1);
		if(!t)queens.erase({col,i});
		else return true;
	}
	return false;
}

/**Função que imprime o tabuleiro*/
void tab(int tam){
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			if(queens.find({i,j})==queens.end())printf("0 ");
			else printf("1 ");
		}
		puts("");
	}
}

int main(void){
	int a=4;
	scanf("%d",&a);
	queens.clear();
	nQueens(a,0);
	tab(a);
	return 0;
}	
