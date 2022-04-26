#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX

using namespace std;

int dp[MAX];

/** função que calcula se é possivel dar um troco com um dado conjunto de moedas*/
int solve(int x, vector<int>& c){
	if(x==0)return 1;
	if(x<0)return 0;

	for(int i=0;i<c.size();i++)
		if(solve(x-c[i],c))return dp[x-c[i]]=1;

	return dp[x]=0;
}
