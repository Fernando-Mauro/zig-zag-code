//incompleto
#include <bits/stdc++.h>

using namespace std;

struct posiciones{
   int x_inicial;
   int y_inicial;
   int x_final;
   int y_final;
};

bool comprobar(int indice, int xInicialActual, int yInicialActual, int xFinalActual, int yFinalActual, vector <posiciones> &ventanas){
   if(indice < (ventanas.size() - 2)){
      if 
   }
}
int indice = 0;
int encima(vector <posiciones> &ventanas){
   for(int i = indice;i < ventanas.size();++i){
      int xInicialActual = ventanas[i].x_inicial, yIniciaActual = ventanas[i].y_inicial, xFinalActual = ventanas[i].x_final,
      yFinalActual = ventanas[i].y_final;
      comprobar(i, xInicialActual, yIniciaActual, xFinalActual, yFinalActual, ventanas);
   }
}
int main(){
   int n;
   cin >> n;
   vector <posiciones> ventanas(n);
   int x_i, y_i, x_f, y_f;
   for(int i = 0; i < n; ++i){
      cin >> x_i >> y_i >> x_f >> y_f;
      ventanas[i] = {x_i,y_i, x_f, y_f};     
   }
   //break point xD
   return 0;
}