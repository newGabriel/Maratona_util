#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> maxSubSet(vector<int> v){
	vector<int> m;
	m.resize(v.size());
	m[0] = 1;
	int max=0;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				m[i] = fmax(m[i],m[j]+1);
			}
		}
		if(max<m[i]){
			max = m[i];
		}
	}
	return m;
}

int main(void){
	vector<int> v = {6,2,5,1,7,4,8,3};
	vector<int> m = maxSubSet(v);
	for(int i: m)cout<<i<<endl;
	return 0;
}
