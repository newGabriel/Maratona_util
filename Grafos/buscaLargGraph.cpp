#define N 10000

using namespace std;

vector<int> g[N];
int componente[N];
int valor;

void BFS(int x){
	queue<int> fila;
	fila.push(x);
	componente[x] = valor;
	int atual = 0;
	while(!fila.empty()){
		int v = fila.front();
		fila.pop();
		for(int i=0;i<g[v].size();i++){
			int u = g[v][i];
			if(componente[u]==-1){
				componente[u] = componente[v];
				fila.push(u);
			}
		}
	}
}
