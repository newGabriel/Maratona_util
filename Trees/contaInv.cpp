#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 1005

using namespace std;

int n;
int v[MAX];
int bit[MAX];

void add(int k,int x){
	while(k<=n){
		bit[k]+=x;
		k += k&-k;
	}
}

int sum(int k){
	int s=0;
	while(k>=1){
		s+=bit[k];
		k-=k&-k;
	}
	return s;
}

int main(void){
	int iv=0;
	scanf("%d",&n);
	memset(bit,0,n*sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=n-1;i>=0;i--){
		iv += sum(v[i]);
		add(v[i],1);
	}
	printf("%d\n",iv);
	return 0;
}
