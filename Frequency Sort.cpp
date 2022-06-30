// https://omegaup.com/arena/problem/Frequency-Sort
// https://www.geeksforgeeks.org/sort-elements-by-frequency/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ulli;
struct colection{
   ulli element;
   int count;
   int first_release;
};
bool ordenar(colection &first_node, colection &second_node){
   if(first_node.count == second_node.count){
      if(first_node.first_release < second_node.first_release){
         return true;
      }
      if(second_node.first_release < first_node.first_release){
         return false;
      }
   }
   if(first_node.count > second_node.count){
      return true;
   }else{
      return false;
   }
}
int main(){
   int n, maximoNumero;
   cin >> n >> maximoNumero;
   ulli aux;
   map <ulli, colection> numeros;
   for(int i = 0; i < n; i++){
      cin >> aux;
      auto el = numeros.find(aux);
      if( el != numeros.end()){
         el -> second.count++;
      }else{
         numeros.insert({aux,{aux, 1, i + 1}});
      }
   }
   vector <colection> contados;
   for( auto it = numeros.begin(); it != numeros.end(); it++){
      contados.push_back(it -> second);
   }
   sort(contados.begin(), contados.end(), ordenar);
   for(int i = 0; i < contados.size(); i++){
      for(int j = 0; j < contados[i].count;j++){
         cout << contados[i].element << " ";
      }
   }
   return 0;
}