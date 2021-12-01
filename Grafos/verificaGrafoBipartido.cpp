void colore(int x){
	
	color[x] = 0;
	
	vector<int> fila;
	fila.push_back(x);
	
	int pos = 0;
	
	while(pos < (int)fila.size()){
		
		int atual = fila[pos];
		pos++;
		
		for(int i = 0;i < (int)g[atual].size();i++){
			
			int v = g[atual][i];
			
			if(color[v] == -1){
				color[v] = 1 - color[atual];
				fila.push_back(v);
			}
		}
	}
}

bool checa_bipartido(){
	for(int i = 0;i < n;i++){
		if(color[i] == -1){
			colore(i);
		}
	}
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < (int)g[i].size();j++){

			int v = g[i][j];
			if(color[i] == color[v]) return false;
		}
	}
	
	return true;
}
