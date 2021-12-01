#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>


#define MAXN 1010
#define MAXS 1010

using namespace std;

int n,valor[MAXN], peso[MAXS], tab[MAXN][MAXS];

int knapsack(int obj,int aguenta){
  if(tab[obj][aguenta]>=0)return tab[obj][aguenta]; //se já calculamos esse estado anteriormente o retornamos
  if(obj==n||!aguenta)return tab[obj][aguenta]=0; //se não houver mais objetos, ou o espaço da mochila acabar não podemos adicionar nada
  int nao = knapsack(obj+1,aguenta); //recursão para o caso que não adicionamos o $obj
  if(peso[obj]<=aguenta){ //se for possivel adicionar $obj à mochila
    int coloca=valor[obj]+knapsack(obj+1,aguenta-peso[obj]); //recursão para o caso que adicionamos o $obj
    return tab[obj][aguenta]=max(coloca,nao); //retornamos a melhor opção de combinação
  }
  return tab[obj][aguenta]=nao; // caso não seja possivel adcionar $obj resta apenas retornas a melhor combinação sem ele
}

int main(void){
  n=3;
  
  memset(tab,-1,sizeof(tab));
  
  valor[0]=9;
  valor[1]=5;
  valor[2]=5;
  
  peso[0]=10;
  peso[1]=6;
  peso[2]=6;
  
  printf("%d\n",knapsack(0,12));
  return 0;
}
