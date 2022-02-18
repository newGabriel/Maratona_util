#include <iostream>

typedef unsigned long long int LL;

LL mdc(LL a, LL b){
	if(b==0)return a;
	else return mdc(b,a%b);
}

LL mmc(LL a, LL b){
	return (a*b)/mdc(a,b);
}
