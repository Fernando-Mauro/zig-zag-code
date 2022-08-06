// https://omegaup.com/arena/problem/OIEG2013SSB
#include <bits/stdc++.h>

using namespace std;

bool DFS(map <int, vector <int>> &cuartos, auto it, int salida){
   for(int i = 0; i < it.second.size(); ++i){
      if(it.second[i] == salida){
         return true;
      }
   }
   return 0;
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   map <int, vector <int>>cuartos;
   int n, e, tiempo;
   cin >> n >> e >> tiempo;
   int a, b;
   int salida = n;
   while(e--){
      cin >> a >> b;
      auto it = cuartos.find(a);
      if(it != cuartos.end()){
         cuartos[a].push_back(b);
      }else{
         cuartos.insert({a, vector <int> (1,b)});
      }
   }
   for(const auto &it : cuartos){
      if(DFS(cuartos,it,salida)){
         cout << "Salida";
      }
   }
   return 0;
}