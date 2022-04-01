#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
   int numero;
   cin >> numero;
   string cadena;
   int longitud = 0;
   for(int i = 1; i <= numero; ++i){
      cadena = to_string(i);
      longitud += cadena.size();
   }
   cout << longitud;
   return 0;
}