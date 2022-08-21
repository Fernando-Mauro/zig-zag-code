// https://omegaup.com/arena/problem/abre
#include <bits/stdc++.h>

using namespace std;

pair <int, int> coordenada = {0,0};

vector <string> jeroglifos(70); 
vector <string> mapa(5);

void comprobar(int indice){
   for(int i = 0; i < 14; ++i){
      for(int j = 0; j < 5; ++j){
         if(jeroglifos[i][j] == mapa[i][j]);
      }
   }
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   for(int i = 0; i < 70; ++i){ 
      getline(cin, jeroglifos[i]);
   }
   for(int i = 0; i < 5; ++i){ 
   getline(cin, mapa[i]);
   }
   for(int i = 0; i < mapa[0].size(); i += 5){
      comprobar(i);
   }
   return 0;
}