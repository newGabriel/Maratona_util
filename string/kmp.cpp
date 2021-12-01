#include <stdio.h>
#include <iostream>

#define MAX 100010

using namespace std;

string t,p;
int b[MAX];

void kmpPreprocess(){
	int i=0,j=-1;
	b[0]=-1;
	while(i<p.size()){
		while(j>=0&&p[i]!=p[j])j=b[j];
		i++;
		j++;
		b[i]=j;
	}
}

void kmpSearch(){
	int i=0,j=0;
	while(i<t.size()){
		while(j>=0&&t[i]!=p[j])j = b[j];
		i++;
		j++;
		if(j==p.size()){
			printf("P is found at index %d in T\n",i-j);
			j = b[j];
		}
	}
}

int main(void){
	
}
