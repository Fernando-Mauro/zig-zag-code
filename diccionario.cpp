#include <bits/stdc++.h>

using namespace std;

void buscar(map <string, int> &palabras, string &palabra, int &pos){
   if(palabras.find(palabra) != palabras.end()){
      cout << palabras[palabra] << " ";
   }else{
      cout << palabra << " ";
      palabras[palabra] = pos;
      pos++;
   }
}
int main(){
   int pos = 1;
   map <string, int> palabras;
   int n;
   cin >> n;
   string palabra;
   while(n--){
      cin >> palabra;
      buscar(palabras, palabra, pos);
   }
   return 0;
}