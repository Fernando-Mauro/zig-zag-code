// Compilar con c++ 17
#include <bits/stdc++.h>

using namespace std;

typedef tuple <int,int,int> iii;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   
   vector <iii> cum;
   
   cum.emplace_back(5,24,-1980);
   cum.emplace_back(5,24,-1982);
   cum.emplace_back(11,13,-1983);
   
   sort(cum.begin(), cum.end());

   for(auto &[mes,dia,anio]:cum){
      printf("%d %d %d\n", mes, dia, -anio);
   }
   return 0;
}