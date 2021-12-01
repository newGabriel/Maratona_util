#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int maxSum(int *a,int n){
	int best = 0, sum = 0;
	for(int i=0;i<n;i++){
		sum = max(a[i],sum+a[i]);
		best = max(best,sum);
	}
	return best;
}

int main(void){
	int a[8] = {-1,2,4,-3,5,2,-5,2};
	int sum = maxSum(a,8);
	printf("%d\n",sum);
	return 0;
}
