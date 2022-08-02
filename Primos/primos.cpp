// Como crear una criba y generar los numeros primos hasta MAX
#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

vector <int> numerosPrimos;
void criba(){
   bitset <MAX> primos;
   //se declara un set
   primos.set();
   for(int i = 2; i <= MAX; ++i){
      //si el numero actual es true se agrega ese numero a los primos
      if(primos[i]){
         numerosPrimos.push_back(i);
         //se recorren los multiplos del i hasta el maximo, 
         for(int j = i * 2; j <= MAX; j += i){
            //se hacen falsos a los multiplos de i
            primos.reset(j);
         }
      }
   }
}
int main(){
   criba();
    for(int i = 0; i < numerosPrimos.size(); ++i){ 
      cout << numerosPrimos[i] << endl;
   }
}