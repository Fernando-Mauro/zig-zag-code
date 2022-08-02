// https://omegaup.com/arena/problem/ocp
#include <bits/stdc++.h>

using namespace std;

void mete(int a, stack <int> &pila){
   pila.push(a);
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector <int> arreglo(n);
   stack <int> pila;
   for(int i = 0; i < n; ++i){ 
      cin >> arreglo[i];
   }
   for(int i = 0; i < n; ++i){
      if(arreglo[i] > pila.size()){
         mete(arreglo[i], pila);
      }else{
         while(arreglo[i]--){
            pila.pop();
         }
      }
   }
   cout << pila.size() << endl;
   while(!pila.empty()){
      cout << pila.top() << " ";
      pila.pop();
   }
   return 0;
}