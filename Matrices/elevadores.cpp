// https://omegaup.com/arena/problem/Elevadores
#include <bits/stdc++.h>

using namespace std;

struct elevador
{
   int posicion;
   int pisoInicial;
   int pisoFinal = pisoInicial + 1;
};

int caminar(int posicionRoco, int pisoActualRoco, vector<elevador> &elv, int extremo)
{
   // pisoInicial del elevador que esta en su misma posicion (horizontal)
   while (posicionRoco != extremo)
   {
      int pisoInicialElv = elv[posicionRoco - 1].pisoInicial;
      int pisoFInalElv = elv[posicionRoco - 1].pisoFinal;
      if (posicionRoco == extremo)
      {
         return pisoActualRoco;
      }
      if (pisoInicialElv == pisoActualRoco)
      {
         // cout << "Bingo, hay un elevador que sube frente a mi";
         pisoActualRoco++;
      }
      else if (pisoFInalElv == pisoActualRoco)
      {
         // cout << "Bingo, hay un elevador que baja frente a mi";
         pisoActualRoco--;
      }
      posicionRoco++;
   }
   return pisoActualRoco;
}
int main()
{

   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int pisos, elevadores;
   cin >> pisos >> elevadores;
   vector<elevador> elv(elevadores);
   for (int i = 0; i < elevadores; i++)
   {
      int inicial;
      cin >> inicial;
      elv[i].posicion = i + 1;
      elv[i].pisoInicial = inicial;
      elv[i].pisoFinal = inicial + 1;
   }
   for (int i = 0; i < pisos; i++)
   {
      // posicion horizontal
      int posicionRoco = 1;
      // piso vertical
      int piso = i + 1;
      cout << caminar(posicionRoco, piso, elv, elevadores + 1) << endl;
   }
}