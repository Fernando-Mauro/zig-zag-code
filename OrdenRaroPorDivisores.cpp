// https://omegaup.com/arena/problem/Orden-raro-por-divisores
#include <bits/stdc++.h>

using namespace std;
// numero y cantidad de divisores del numero
map <int, int> divisores;

int buscarDivisores(int numero){
   int divisoresNum = 1;
   for(int i = 1; i < ((numero / 2) + 1); i++){
      if(numero % i == 0) divisoresNum++;
   }
   return divisoresNum;
}
bool ordenar(int &firstNode, int &secondNode){
   auto divisoresFirst = divisores.find(firstNode);
   auto divisoresSecond = divisores.find(secondNode);
   int divisoresNewFirst = 0;
   int divisoresNewSecond = 0;
   if(divisoresFirst == divisores.end()){
      divisoresNewFirst = buscarDivisores(firstNode);
      divisores.insert({firstNode, divisoresNewFirst});
   }else{
      divisoresNewFirst = divisoresFirst -> second; 
   }
   if(divisoresSecond == divisores.end()){
      divisoresNewSecond = buscarDivisores(secondNode);
      divisores.insert({secondNode, divisoresNewSecond});
   }else{
      divisoresNewSecond = divisoresSecond -> second;
   }
   if(divisoresNewFirst == divisoresNewSecond){
      if(firstNode < secondNode){
         return false;
      }else{
         return true;
      }
   }
   if(divisoresNewFirst < divisoresNewSecond){
      return true;
   }
   if(divisoresNewSecond < divisoresNewFirst){
      return false;
   }
}
int main(){
   int n;
   cin >> n;
   vector <int> numeros(n);
   for(int i = 0; i < n; i++){
      cin >> numeros[i];
   }
   sort(numeros.begin(),numeros.end(), ordenar);
     for(int i = 0; i < n; i++){
      cout << numeros[i] << " ";
   }
   return 0;
}