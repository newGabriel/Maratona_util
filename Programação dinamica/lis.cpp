#include <algorithm>
#include <vector>

using namespace std;

int lis(vector<int> &v){

	vector<int> pilha;

	for(int i=0;i<v.size();i++){
		
		vector<int>::interator it = lower_bound(pilha.begin(), pilha.end(),v[i]);
		if(it==pilha.end())pilha.push_back(v[i]);
		else *it = v[i];

	}

	return pilha.size();
}
