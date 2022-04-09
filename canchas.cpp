#include <bits/stdc++.h>

using namespace std;

bool comprobar(pair <int,int> x, pair <int,int> y, pair <int, int> lado){
   // y
   if(lado.first >= x.first && lado.first <= y.first && lado.second >= x.second && lado.second <= y.second){
      return true;
   }
   return false;
}
int main(){
   vector <pair <int,int>> primero;
   vector <pair <int,int>> segundo;
   int x, y;
   for(int i = 0; i < 2; i++){
      cin >> x >> y;
      primero.push_back(make_pair(x,y));
   }
   primero.push_back(make_pair(primero[0].first,primero[1].second));
   primero.push_back(make_pair(primero[1].first,primero[0].second));
   for(int i = 0; i < 2; i++){
      cin >> x >> y;
      segundo.push_back(make_pair(x,y));
   }
   segundo.push_back(make_pair(segundo[0].first,segundo[1].second));
   segundo.push_back(make_pair(segundo[1].first,segundo[0].second));
   //imprimir dos arreglo
   int areaPrimero = (primero[1].first - primero[0].first) * (primero[1].second - primero[0].second);
   int areaSegundo = (segundo[1].first - segundo[0].first) * (segundo[1].second - segundo[0].second);
   int areaTotal = areaPrimero + areaSegundo;
   vector <pair<int,int>> incluyentes;
   string orden;
   for(int i = 0; i < segundo.size(); i++){
      bool bandera = comprobar(primero[0], primero[1], segundo[i]);
      if(bandera){
          if(i == 0 || i == 2){
         orden.push_back('u');
      }else if(i == 1 || i == 3){
         orden.push_back('d');
      }
         incluyentes.push_back(segundo[i]);
      }
   }
   int restar = 0, restar2 = 0;
   for(int i = 0; i < incluyentes.size(); ++i){
      if(orden[i] == 'u'){
         int multiplo1 =  abs(incluyentes[i].first - primero[1].first) ;
         int multiplo2 = abs(incluyentes[i].second - primero[1].second);
         restar = multiplo1 * multiplo2;
      }else if(orden[i] == 'd'){
         restar = (incluyentes[i].first - primero[0].first) * (incluyentes[i].second - primero[0].second);
      }
   }      
   cout << areaTotal - restar;

   return 0;
}
