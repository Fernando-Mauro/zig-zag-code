// https://omegaup.com/arena/problem/Al-reves-20
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int inicio, final;
   cin >> inicio >> final;
   string texto;
   cin.ignore();
   getline(cin, texto);
   for(int i = 0; i < inicio; ++i){
      cout << texto[i];
   }
   for(int i = final; i >= inicio; --i){
      cout << texto[i];
   }
   for(int i = final + 1; i < texto.size(); ++i){
      cout << texto[i];
   }
   return 0;
}