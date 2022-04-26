#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAXN 105
#define MAXL 20

using namespace std;

vector<int> g[MAXN];

int nivel[MAXN];
int pai[MAXN];
int ancestral[MAXN][MAXL];

void DFS(int u){
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i];
		if(nivel[v]==-1){
			pai[v] = u;
			nivel[v] = nivel[u]+1;
			DFS(v);
		}
	}
}

int LCA(int u, int v){
	if(nivel[u] < nivel[v]) swap(u,v);
	
	for(int i=MAXL-1;i>=0;i--){
		if(nivel[u] - (1<<i) >= nivel[v])
			u = ancestral[u][i];
	}

	if(u==v)return u;

	for(int i = MAXL-1;i>=0;i--){
		if(ancestral[u][i] != -1 
			&& ancestral[u][i]!=ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
	}

	return ancestral[u][0];
}

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		pai[i] = -1;
		nivel[i] = -1;
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	pai[1] = 0;
	nivel[1] = 0;
	DFS(1);

	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXL;j++){
			ancestral[i][j] = -1;
		}
	}
	for(int i=1;i<=n;i++)ancestral[i][0] = pai[i];
	for(int j=1;j<=MAXL;j++){
		for(int i=1;i<=n;i++){
			if(ancestral[i][j-1]!=-1)
				ancestral[i][j]=ancestral[ancestral[i][j-1]][j-1];
		}
	}
	int x,y;
	scanf("%d%d",&x,&y);
	printf("%d\n",LCA(x,y));

	return 0;
}
