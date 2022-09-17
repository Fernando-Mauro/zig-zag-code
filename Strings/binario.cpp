#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

int binarioAdecimal(string binario){
   int total = 0, potencia = 0;
   for(int i = binario.size() - 1; i >= 0; --i){
      if(binario[i] == '1'){
         total += pow(2,potencia);
      }
      potencia += 1;
      // potencia++;
   }
   return total;
}
void binarioAtexto(){
   string cadena;
   getline(cin,cadena);
   // 01100110 01100101 01110010 01101110 01100001 01101110 01100100 01101111
   stringstream separarCadena(cadena);
   string octeto;
   while(getline(separarCadena, octeto, ' ')){
      int valorEnDecimal = binarioAdecimal(octeto);
      char letra = char(valorEnDecimal);
      cout << letra;
   }
}
// suscribete
// s = 115
// 115 % 2 = 1
// 57 % 2 = 1
// 28 % 2 = 0
// 14 % 2 = 0
// 7 % 2 = 1
// 3 % 2 = 1
// 1 % 2 = 1
// 0 0 1 1 1 0 0 1 1
string decimalAbinario(int valorAscii){
   string binario = "";
   while(valorAscii > 0){
      if(valorAscii % 2 == 0){
         binario = "0" + binario;
      }else{
         binario = "1" + binario;
      }
      valorAscii /= 2;
   }
   while(binario.size() < 8){
      binario = "0" + binario;
   }
   return binario;
}

void textoAbinario(){
   string cadena;
   getline(cin,cadena);
   for(int i = 0; i < cadena.size(); ++i){
      int valorAscii = int(cadena[i]);
      cout << decimalAbinario(valorAscii) << " ";
   }
}
// 01010101
// 2 ^ 0 = 1
// 2 ^ 2 = 4
// 2 ^ 4 = 16
// 2 ^ 6 = 64
// 1 + 4 + 16 + 64 = 85
// 01010011 01110101 01110011 01100011 01110010 01101001 01100010 01100101 01110100 01100101
int main(){
   int opcion;
   cin >> opcion;
   cin.ignore();
   switch(opcion){
      case 1: binarioAtexto(); break;
      case 2: textoAbinario(); break;
   }
}