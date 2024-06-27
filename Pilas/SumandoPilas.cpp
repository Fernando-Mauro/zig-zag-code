// https://omegaup.com/arena/problem/Sumando-con-pilas
#include <bits/stdc++.h>

using namespace std;
stack <int> pila;

void agrega(int n){
   pila.push(n);
}

void consume(){
   int suma = 0;
   suma += pila.top();
   pila.pop();
   suma += pila.top();
   pila.pop();
   pila.push(suma);
}
void imprimir (){
   cout << pila.top() << endl;
}
int main(){
   int instrucciones = 0;
   cin >> instrucciones;

   string cadena;
   int aux = 0;
   
   while(instrucciones--){
      // AGREGA 1
      cin >> cadena;

      if(cadena == "AGREGA"){
         cin >> aux;
         agrega(aux);
      }else if( cadena == "CONSUME"){
         consume();
      }else{
         imprimir();
      }
   }
   
   return 0;
}