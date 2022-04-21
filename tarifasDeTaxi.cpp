#include <iostream>
#include <vector>
using namespace std;

int recorrerMetros(vector <int> &tiempos, int segudnos, int metros);
int main(){
    std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
   int banderazo, metros, segundos, tiempoTotal;
   cin >> banderazo >> metros >> segundos >> tiempoTotal;
   vector <int> tiempos;
   int cantidad;
   while(tiempoTotal--){
      cin >> cantidad;
      tiempos.push_back(cantidad);
   }
   cout <<recorrerMetros(tiempos, segundos, metros) + banderazo;
   return 0;
}
int recorrerMetros(vector <int> &tiempos, int segundos, int metros){
   int total = 0;
   int segundosRecorridos = 0;
   int segundosCobrados = 0;
   int sobrante = 0;
   int metrosRecorridos = 0;
   int metrosCobrados = 0;
   int metrosAnterior = 0;
   for(int i = 0; i < tiempos.size(); ++i){
      metrosAnterior = metrosCobrados;
      metrosCobrados += (tiempos[i] - metrosCobrados * metros) / metros;
      sobrante = (tiempos[i] - metrosCobrados * metros);
      segundosRecorridos++;
      if(metrosCobrados != metrosAnterior){
         total += metrosCobrados - metrosAnterior;
         segundosRecorridos = 0;
      }else{
         if(segundosRecorridos / segundos >= 1){
            total += segundosRecorridos / segundos;
            segundosRecorridos = 0;
         }
      }
   }
   return total;
}
