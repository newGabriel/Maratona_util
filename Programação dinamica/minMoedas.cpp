int minMoedas(int n,vector<int> bit){
	//n = valor total
	//bit = moedas disponiveis
	int memo[n+1];
	memo[0]=0;
	for(int i=1;i<=n;i++){
		memo[i] = INT32_MAX;
		for(int j=0;j<bit.size();j++){
			if(i-bit[j]>=0){
				memo[i] = fmin(memo[i], memo[ i-bit[j] ]+1);
			}
		}
	}
	return memo[n];
}
