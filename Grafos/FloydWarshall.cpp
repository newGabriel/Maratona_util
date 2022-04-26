/**
@brief floydWarshall
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	int g[n+1][n+1];
	
	//settando o grafo com todas as distancias maximas
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j] = i==j?0:INT16_MAX;
		}
	}
	
	//leitura do grado em uma matrix de adjacencia
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a][b] = c;
		g[b][a] = c;
	}
	
	//algoritimo que calcula a distancia minima dos nós do grafo de todos para todos em O(n³)
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
			}	
		}
	}
	
  return 0;
}
