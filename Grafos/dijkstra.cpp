#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 10100

using namespace std;

typedef pair<int,int> pii; ///para ganhar velocidade ou mater a organização do codigo pode se usar um typedef para um tipo que se repete muitas vezes

//-----Caracteristicas do grafo-------
int n; //número de vertices
int dist[N]; //distancias de x para todos outros vertices
bool visit[N]; //vertices visitados
vector<pii> g[N]; //grafo 
//------------------------------------

void dijkstra(int x){
	for(int i=1;i<=n;i++){
		dist[i]=INT32_MAX;
		visit[i]=false;
	}
	dist[x]=0;
	priority_queue<pii> q;
	q.push({0,x});
	while(!q.empty()){
		int a = q.top().second;
		q.pop();
		if(visit[a])continue;
		visit[a]=true;
		for(auto u : g[a]){
			int b = u.first, w = u.second;
			if(dist[a]+w<dist[b]){
				dist[b] = dist[a]+w;
				q.push({-dist[b],b});
			}
		}
	}
}


int main(){
	
}
