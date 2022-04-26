#include <iostrem>

using namespace std;

/**Função que calcula se um número é primo em O(sqrt(x))*/
bool primo(int x){
	if(x==1)return 0;
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	
}
