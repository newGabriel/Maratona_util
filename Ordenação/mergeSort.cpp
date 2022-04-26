#include <stdio.h>
#include <iostream>
#include <vector>

#define INF 1000000

using namespace std;
/**Algoritimo de merge sort (descomente os trechos para retornar a contagem de inversões)*/
void merge_sort(vector<int> &v){
	
	if(v.size()==1)return; //se o vetor só tiver um item já está ordenado

  //int inv = 0

	vector<int> u1,u2; //vetores auxiliares

	for(int i=0;i<v.size()/2;i++){
		u1.push_back(v[i]);
	}
	for(int i=v.size()/2;i<v.size();i++){
		u2.push_back(v[i]);
	}
	
	/*inv+=*/merge_sort(u1);
	/*inv+=*/merge_sort(u2);
	
	u1.push_back(INF);
	u2.push_back(INF);

	int _1=0, _2=0;
	
	for(int i=0;i<v.size();i++){
		if(u1[_1]<=u2[_2]){
			v[i] = u1[_1];
			_1++;
		}
		else{
			v[i] = u2[_2];
			_2++;
		  //inv+=u1.size()-_1;
		}
	}
	return /*inv*/;
}

int main(void){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}

	merge_sort(v);

	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}puts("");
	
	return 0;
}

