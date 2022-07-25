// https://omegaup.com/arena/problem/Abigael-vs-Daniel
#include <bits/stdc++.h>

using namespace std;

#define MAX 900000
typedef unsigned long long int ui64;
bitset <MAX> criba;

vector <int> primos;

vector <int> primosAbigael;

vector <int> primosDaniel;

void rellenarCriba(){
   criba.set();
   criba.reset(0);
   criba.reset(1);
   for(int i = 2; i < MAX; ++i){
      if(criba[i]){
         primos.push_back(i);
         for(int j = i * 2; j < MAX; j += i){
            criba.reset(j);
         }
      }
   }
}

void buscarFactoresDaniel(ui64 n){
   for(int i = 0; primos[i] < sqrt(n) && n > 1; ++i){
      if(n % primos[i] == 0){
         primosDaniel.push_back(primos[i]);
         while(n % primos[i] == 0){
            n /= primos[i];
         }
      }
   }
   if(n != 1){
      primosDaniel.push_back(n);
   }
}

void buscarFactoresAbigael(ui64 n){
   for(int i = 0;primos[i] < sqrt(n) && n > 1; ++i){
      if(n % primos[i] == 0){
         primosAbigael.push_back(primos[i]);
         while(n % primos[i] == 0){
            n /= primos[i];
         }
      }
   }
   if(n != 1){
      primosAbigael.push_back(n);
   }
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   rellenarCriba();
   ui64 numeroAbigael, numeroDaniel;
   cin >> numeroDaniel >> numeroAbigael;
   buscarFactoresDaniel(numeroDaniel);
   buscarFactoresAbigael(numeroAbigael);
   if(primosAbigael.size() > primosDaniel.size()){
      cout << "Abigael" << endl;
      for(int i = 0; i < primosDaniel.size(); ++i){
         cout << primosDaniel[i] << " ";
      }
      cout << endl;
      for(int i = 0; i < primosAbigael.size(); ++i){ 
         cout << primosAbigael[i] << " ";
      }
   }else if(primosAbigael.size() == primosDaniel.size()){
      cout << "Empate" << endl;
      for(int i = 0; i < primosDaniel.size(); ++i){
         cout << primosDaniel[i] << " ";
      }
      cout << endl;

      for(int i = 0; i < primosAbigael.size(); ++i){ 
         cout << primosAbigael[i] << " ";
      }
   }else{
       cout << "Daniel" << endl;
      for(int i = 0; i < primosDaniel.size(); ++i){
         cout << primosDaniel[i] << " ";
      }
      cout << endl;

      for(int i = 0; i < primosAbigael.size(); ++i){ 
         cout << primosAbigael[i] << " ";
      }
   }
   return 0;
}