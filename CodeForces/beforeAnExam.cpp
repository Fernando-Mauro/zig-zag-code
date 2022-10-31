// https://codeforces.com/contest/4/problem/B
#include <bits/stdc++.h>

using namespace std;

struct day{
   int min;
   int max;
};

int solve(vector <day> &diasArr, int tiempo){
   int tiempoActual = 0;
   for(int i = 0; i < diasArr.size(); ++i){
      tiempoActual += diasArr[i].max;
      if(tiempoActual >= tiempo){
         
      }
   }  
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int dias, tiempo;
   cin >> dias >> tiempo;
   vector <day> diasArr(dias);
   int maximoTotal = 0;
   for(int i = 0; i < dias; ++i){
      int maximo, minimo;
      cin >> minimo >> maximo;
      maximoTotal += maximo;
      diasArr[i].min = minimo;
      diasArr[i].max = maximo;
   }
   // descartar que no se pueda completar
   if(maximoTotal < tiempo){
      cout << "NO" << endl;
      return 0;
   }else{
      solve(diasArr, tiempo);
   }
   return 0;
}