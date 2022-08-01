#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ui64;
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   ui64 aux;
   cin >> n;
   for(int i = 0; i < n; i++){
      cin >> aux;
      cout << (aux * ((aux * (aux + 1)) / 2)) << endl;
   }
   return 0;
}