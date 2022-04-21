#include <bits/stdc++.h>

using namespace std;

struct lado{
   int x = 0;
   int y = 0;
};
int main(){
   vector <lado> cuadrado1;
   vector <lado> cuadrado2;
   int xaux, yaux;
   cin >> xaux >> yaux;
   cuadrado1.push_back({xaux, yaux});
   cin >> xaux >> yaux;
   cuadrado1.push_back({xaux, yaux});
   cuadrado1.push_back({cuadrado1[0].x, cuadrado1[1].y});
   cuadrado1.push_back({cuadrado1[1].x, cuadrado1[0].y});
   cin >> xaux >> yaux;
   cuadrado2.push_back({xaux, yaux});
   cin >> xaux >> yaux;
   cuadrado2.push_back({xaux, yaux});
   cuadrado2.push_back({cuadrado2[0].x, cuadrado2[1].y});
   cuadrado2.push_back({cuadrado2[1].x, cuadrado2[0].y});
   
   int breaking;
   return 0;
}