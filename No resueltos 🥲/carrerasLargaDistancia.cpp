// https://omegaup.com/arena/problem/Carrera-de-Larga-Distancia/
#include <iostream>

using namespace std;

int main(){
   int minutos,tramos, tiempoSubida,TiempoPlano,tiempoBajada;
   cin >> minutos >> tramos >> tiempoSubida >> TiempoPlano >> tiempoBajada;
   int bajadas, subidas,plano;
   char opcion;
   while(tramos--){
      cin >> opcion;
      switch (opcion)
      {
      case 'U': subidas++;
         break;
      case 'F':  plano++;
         break;
      case 'D':  bajadas++;
         break;
      }
   }
   int tiempoIr = (tiempoBajada * bajadas)+ (tiempoSubida * subidas) + (TiempoPlano + plano);
   int tiempoVolver = (tiempoBajada * subidas) + (tiempoSubida * bajadas) + (TiempoPlano + plano);
   return 0;
}