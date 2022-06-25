// https://omegaup.com/arena/problem/hojas2
#include <bits/stdc++.h>

using namespace std;
int convertir(int numero, int base){
   int digitos = 0;
   int copNum = numero;
   string cadena = "";
   while(numero >= base){
      cadena.insert(0, to_string(numero % base));
      numero /= base;
      digitos++;
   }
   cadena.insert(0, to_string(numero));
   cout <<"Decimal: " << copNum << endl << "Base 4:" <<  cadena << endl;
   // return digitos + 1;
}
int main(){
   int numerosAEscribir = 1000, base = 4, digitosPorLibreta;
   // cin >> numerosAEscribir >> base >> digitosPorLibreta;
   int sumaDigitos = 0;
   for(int i = 1;i <= numerosAEscribir; i++){
      convertir(i, base);
   }
   // if(sumaDigitos % digitosPorLibreta == 0){
   //    cout << sumaDigitos / digitosPorLibreta;
   // }else{
   //    cout << (sumaDigitos / digitosPorLibreta) + 1;
   // }
   cout << convertir(1,2);
}