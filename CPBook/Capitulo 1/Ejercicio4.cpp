#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n; cin >> n;
   set <int> numbers;
   while(n--){
      int aux; cin >> aux;
      numbers.insert(aux);
   }
   for(auto it:numbers) 
      cout << it << endl;
   return 0;
}