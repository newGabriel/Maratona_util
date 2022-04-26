/**
@brief maior sequencia comum
*/
#include <algorithm>

#define MAXN 1010

using namespace std;

int s1[MAXN], s2[MAXN], tab[MAXN][MAXN];

int lcs(int a, int b){

	if(tab[a][b]>=0)return tab[a][b];

	if(a==0 || b==0)return tab[a][b]=0;

	if(s1[a]==s2[b])return 1+lcs(a-1,b-1);

	return tab[a][b] = max(lcs(a-1,b),lcs(a,b-1));
}

int lcs2(int a, int b){
	int tab[a+1][b+1];
	
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			if(i==0||j==0)
				tab[i][j]=0;
			else if(s1[i-1]==s2[j-1])
				tab[i][j] = tab[i-1][j-1]+1;
			else
				tab[i][j] = max(tab[i-1][j],tab[i][j-1]);
		}
	}
	return tab[a][b];
}
