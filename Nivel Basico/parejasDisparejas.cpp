// https://omegaup.com/arena/problem/Disparejas/
#include <iostream>

using namespace std;

long long int suma(int n){
   long long int total = 0;
   for(int i = 1; i < n; ++i){
      if(n % i == 0){
         total += i;
      }
   }
   return total;
}
int comprobar(int n, int m){
   if(suma(m) == n && suma(n) == m){
      cout << 0 << " ";
      return 0;
   }else if(suma(m) <= n && suma(n) <= m){
      cout << 1 <<" ";
      return 0;
   }else if(suma(m) > n && suma(n) > m){
      cout << 2 << " ";
      return 0;
   }else {
      cout << 3 << " ";
   }
   return 0;
}
int main(){
   int n, m;
   cin >> n;
   cin >> m;
   long long int totaln = suma(n);
   long long int totalm = suma(m);
   comprobar(n, m);
   comprobar(n, n);
   comprobar(m,m);
   return 0;
}