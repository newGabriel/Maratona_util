/**
@brief ordenação topologica
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> g[n+1];
	vector<int> lista;
	int grau[n+1] = {0};
	/** leitura e construção do grafo*/
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		grau[b]++;
	}
	
	/** coloca os vertices com grau de entrada 0 na fila de processamento*/
	for(int i=1;i<=n;i++){
		if(grau[i]==0)lista.push_back(i);
	}
	
	/** percorre a lista de processamento reduzindo o grau de entrada dos nós vizinhos ao vertice atual
	    os vertices que obtiverem grau 0 são colocados na fila de processamento*/
	int in=0;
	while(in<lista.size()){
		int atual = lista[in];
		in++;
		for(int i=0;i<g[atual].size();i++){
			int v = g[atual][i];
			grau[v]--;
			if(grau[v]==0)lista.push_back(v);
		}
	}
	if(lista.size()<n)printf("IMPOSSIBLE\n"); //se algum nó não for processado não é possivel ordenar topologicamente
	else{
		for(int i : lista){
			printf("%d ",i);
		}printf("\n");
	}
	return 0;
}
