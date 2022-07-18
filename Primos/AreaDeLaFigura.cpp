// https://omegaup.com/arena/problem/Area-de-la-figura
#include <bits/stdc++.h>

using namespace std;

int main(){
   int n = 0;
   cin >> n;
   int longitud =((n - 1) * 2) + 1;
   longitud -= 2;
   int area = 0;
   while  (longitud >= 1){
      area += longitud;
      longitud -= 2;
   }
   area *= 2;
   area += ((n - 1) * 2) + 1;
   cout << area;
   return 0;
}