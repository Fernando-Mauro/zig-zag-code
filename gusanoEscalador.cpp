// https://omegaup.com/arena/problem/gusano_escalador/
#include <iostream>

using namespace std;

int main(){
   int profundidad, avance, retroceso, minutos = 0;
   cin >> profundidad >> avance >> retroceso;
   while(profundidad > 0){
      profundidad -= avance;
      if(profundidad <= 0){
         minutos++;
         break;
      }else{
      profundidad += retroceso;
      minutos += 2;
      }
   }
   cout << minutos << endl;
   return 0;
}