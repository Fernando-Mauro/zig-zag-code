// https://omegaup.com/arena/problem/suma-muchos-p 
#include <bits/stdc++.h> 

using namespace std;
#define MAX 10000
bitset <MAX> criba;
vector <int> primos;

void rellenarCriba(){
   criba.set();
   criba.reset(0);
   primos.push_back(1);
   for(int i = 2; i < MAX; ++i){
      if(criba[i]){
         primos.push_back(i);
         for(int j = i * 2; j < MAX; j += i){
            criba.reset(j);
         }
      }
   }
}
void factorizar(){

}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int numero;
   cin >> numero;
   rellenarCriba();
   // for(int i = 0; i < primos.size(); ++i){ 
   //    cout << primos[i] << endl;
   // }
   for(int i = primos.size() - 1; i >= 0; --i){
      if(numero >= primos[i]){
         numero -= primos[i];
         cout << primos[i] << " ";
         ++i;
      }
   }
   return 0;
}