/**
@brief MST Prim
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define N 10100

using namespace std;

typedef pair<int,int> pii;

int n,m;
int dist[N];
int proc[N];
vector<pii> g[N];

int prim(){
	for(int i=2;i<=n;i++)dist[i] = INT32_MAX;
	dist[1]=0;
	
	priority_queue <pii,vector<pii,greater<pii>> fila;
	fila.push({dist[1],1});
	
	while(true){
		int davez = -1;
		
		while(!fila.empty()){
			int atual = fila.top().second;
			fila.pop();
			
			if(!proc[atual]){
				davez = atual;
				break;
			}
		}
		
		if(davez == -1)break;
		
		proc[davez] = true;
		
		for(int i=0;i<g[davez].size();i++){
			int dista = g[davez][i].first;
			int atual = g[davez][i].second;
			
			if(dist[atual] > dista && !proc[atual]){
				dist[atual] = dista;
				fila.push({dist[atual],atual});
			}	
		}
	}
	int custo_arvore = 0;
	for(int i=1;i<=n;i++)custo_arvore += dist[i];
	
	return custo_arvore;
}
