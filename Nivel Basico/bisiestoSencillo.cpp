// https://omegaup.com/arena/problem/1-Bisiesto-sencillo
#include <bits/stdc++.h>

using namespace std;

bool esBisiesto(int &anio){
   if(anio % 100 == 0 && anio % 400 == 0) return true;
   if(anio % 100 == 0) return false;
   if(anio % 4 == 0) return true;
   return false;
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int anio;
   while(cin >> anio){
      if(esBisiesto(anio)){
         cout << "S" << endl;      
      }else{
         cout << "N" << endl;
      }
   }
   return 0;
}