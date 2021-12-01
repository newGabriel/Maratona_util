typedef pair<int,int> pii;

vector<pii> g[N];

list<int> cyc;

void euler(list<int>::interator i, int u){
	for(int j=0;j<g[u].size();j++){
		pii v = g[u][j];
		if(v.second){
			g[u][j].second = false;
			for(int k=0;k<g[v.first].size();k++){
				pii uu = g[v.first][k];
				if(uu.first == u && uu.second){
					uu.second = false;
					break;
				}
			}
			euler(cyc.insert(i,u), v.first);
		}
	}
}
