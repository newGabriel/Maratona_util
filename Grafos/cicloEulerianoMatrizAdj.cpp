#define N 55

int g[N][N]; //matriz de adjacencia 
int grau[N];  //grau de cada vertice

void euler(int u){ //DFS busca Caminho Ereliano
	for(int i=1;i<=N;i++){ //percorre todos os vertices
		while(g[u][i]){ //reduz as arestas entre o vertice $u e $i
			g[u][i]--;
			g[i][u]--;
			euler(i); //recursao dfs
			printf("%d %d\n",i,u); //printa a aresta #pode ser modificado segundo a resolução de cada problema;
		}
	}
}
