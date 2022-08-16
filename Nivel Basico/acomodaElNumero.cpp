// https://omegaup.com/arena/problem/AcomodandoOMI/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   int numero;
   cin >> numero;
   int aux;
   int pos = 0;
   n -= 1;
   while(n--){
      cin >> aux;
      if(aux < numero) pos++;
   }
   cout << pos << endl;
   return 0;
}