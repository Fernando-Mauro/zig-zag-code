#include <bits/stdc++.h>

using namespace std;

int main(){
   unsigned long long int numero = 0;
   unsigned long long int total= 0;
   int digitos = 1;
   cin >> numero;
   unsigned long long int anterior = 0;
   unsigned long long int i;
   for(i = 10; i < numero; i *= 10){
      total += (i - (anterior)) * digitos;
      anterior = i;
      digitos++;
   }
   total += (numero - (anterior)) * digitos;
   if(numero == 10 || numero == 100 || numero == 1000 || numero == 10000 || numero == 100000 || numero == 1000000 || numero == 10000000 || numero == 100000000 || numero == 1000000000){
      cout << total + digitos;
   }else{
   cout << total + digitos - 1;
   }
   return 0;
}