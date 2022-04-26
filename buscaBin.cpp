/**
@brief busca binaria
*/
int busca(vector<int> v, int n, int in, int f){
	while(in<=f){
		int pos = (f+in)/2;
		if(v[pos]==n)return pos;
		if(v[pos]>n)f = pos-1;
		if(v[pos]<n)in = pos+1;
	}
	return -1;
}
