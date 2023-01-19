// https://omegaup.com/arena/problem/Matriz-con-Mitades-Iguales/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   
   int n, m;
   scanf("%d %d", &n, &m);
   
   vector <vector <int>> first (n, vector <int> (m / 2));
   vector <vector <int>> second (n, vector <int> (m / 2));
   
   for(int i = 0; i < n; ++i){
      for(int j = 0; j < (m / 2); ++j){ 
         scanf("%d", &first[i][j]);
      }
      
      for(int j = 0; j < (m / 2); ++j){ 
         scanf("%d", &second[i][j]);
      }      
   }
   bool bandera = true;
   for(int i = 0; i < n; ++i){
      for(int j = 0; j < (m / 2); ++j){ 
         if(first[i][j] != second[i][j]){
            bandera = false;
            break;
         }
      }      
   }

   printf("%d", bandera);
   return 0;
}