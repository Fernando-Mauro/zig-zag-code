// https://omegaup.com/arena/problem/Bolsas-de-dulces/
#include <iostream>

using namespace std;

int main(){
   int n = 0;
   float total = 0, precio, cantidad;
   cin >> n;
   while(n--){
      cin >> cantidad >> precio;
      total += (cantidad * precio);
   }
   cout << total << endl;
   return 0;
}