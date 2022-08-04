#include <bits/stdc++.h>

using namespace std;

int buscar(int numero, multiset <int> &numeros){
   if(numeros.find(numero) != numeros.end()){
      cout << "YES" << endl;
   }else{
      cout << "NO" << endl;
   }
}
int main(){
   multiset <int> numeros;
   int n;
   cin >> n;
   int aux;
   while(n--){
      cin >> aux;
      buscar(aux, numeros);
      numeros.insert(aux);
   }
   return 0;
}