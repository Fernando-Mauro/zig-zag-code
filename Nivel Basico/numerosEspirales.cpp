// https://omegaup.com/arena/problem/Numero-espirales/
#include <iostream>

using namespace std;

int main(){
   long long int n;
   cin>> n;
   long long int suma = 0;
   for(int i = 0; i <= n; i++){
      suma += (i * i);
   }
   cout << suma;
   return 0;
}