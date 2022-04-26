/**
@brief busca em profundidade
*/
#include <bits/stdc++.h>
#define MAX 1005

using namespace std;

int n,m;
int component[MAX];
vector<int> g[MAX];

void dfs(int x){
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(component[v]==-1){
			component[v] = component[x];
			dfs(v);
		}
	}
}

int main(void){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)component[i]=-1;
    for(int i=0;i<m;i++){
		int a1,a2;
		scanf("%d%d",&a1,&a2);
		g[a1].push_back(a2);
		g[a2].push_back(a1);
	}
	int nc=0;
	for(int i=1;i<=n;i++){
		if(component[i]==-1){
			nc++;
			component[i]=nc;
			dfs(i);
		}
	}
	printf("%d\n",nc);
    return 0;
}

