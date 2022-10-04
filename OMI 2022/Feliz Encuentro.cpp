#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int longitud, preguntas;
   cin >> longitud >> preguntas;
   vector <int> presumas (longitud - 1,0);
   char auxiliar, anterior = ' ';
   for(int i = 0; i < longitud; ++i){
      cin >> auxiliar;
         presumas[i] = presumas[i - 1];
      if(i != 0){
         if(auxiliar == anterior){
            presumas[i] ++;
         }
      }
      anterior = auxiliar;
   }
   for(int i = 0; i < preguntas; ++i){
      int inicio, final;
      cin >> inicio >> final;
      cout << presumas[final] - presumas[inicio] << endl;
   }
   return 0;
}