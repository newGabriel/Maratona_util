#include <stdio.h>
#include <iostream>

#define TAM 128

using namespace std;

int segTree[TAM];

void boild(int a[],int v,int tl,tr){
	if(tl==tr){
		segTree[v]=a[tl];
	}
	else{
		int tm = (tl+tr)/2;
		build(a,v*2,tl,tm);
		build(a,v*2+1,tm+1,tr);
		t[v]=t[v*2]+v[v2+1];
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(l>r)return 0;
	if(l==tl&&r==tr){
		return segTree[v];
	}
	int tm = (tl+tr)/2;
	return sum(v*2,tl,tm,l,min(r,tm))+sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v,int tl,int tr, int pos, int val){
	if(tl==tr){
		segTree[v]=val;
	}
	else{
		int tm = (tl+tr)/2;
		if(pos<=tm){
			update(v*2,tl,tm,pos,val);
		}
		else{
			update(v*2+1,tm+1,tr,pos,val);
		}
		segTree[v]=segTree[v*2]+segTree[v*2+1];
	}
}

int main(void){


}
