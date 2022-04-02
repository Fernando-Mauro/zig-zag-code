#include <iostream>

using namespace std;

long long int suma(int n){
   long long int total = 0;
   for(int i = 2; i < (n / 2) + 1; ++i){
      if(n % i == 0){
         total += i;
      }
   }
   return total + 1;
}
int comprobar(long long int totaln, long long int totalm, int n, int m){
   if(totalm == n && totaln == m){
      cout << 0 << " ";
      return 0;
   }
   if(totalm <= n && totaln <= m){
      cout << 1 <<" ";
      return 0;
   }
   if(totalm >= n && totaln >= m){
      cout << 2 << " ";
      return 0;
   }
   cout << 3 << " ";
   return 0;
}
int main(){
   int n, m;
   cin >> n;
   cin >> m;
   long long int totaln = suma(n);
   long long int totalm = suma(m);
   comprobar(totaln, totalm, n, m);
   comprobar(totaln, totaln, n, n);
   comprobar(totalm, totalm, m,m);
   return 0;
}