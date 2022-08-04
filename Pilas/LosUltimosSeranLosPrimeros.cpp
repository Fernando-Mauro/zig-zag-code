// https://omegaup.com/arena/problem/Los-Ultimos-Seran-Los-Primeros
#include <bits/stdc++.h>

using namespace std;

int main(){
   string nombre;
   stack <string> participantes;
   while(cin >> nombre){
      participantes.push(nombre);
   }
   participantes.pop();
   while(!participantes.empty()){
      cout << participantes.top() << endl;
      participantes.pop();
   }
   return 0;
}