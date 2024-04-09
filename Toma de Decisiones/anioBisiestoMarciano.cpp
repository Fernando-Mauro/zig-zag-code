// https://omegaup.com/arena/problem/abm/
#include <iostream>


using namespace std;

const int diasPorAnio = 686;
const int diasPorMes = 57;
const int anioInicial = 2001;

int main(){
   int anioFinal, mesFinal, diaFinal;
   cin >> diaFinal >> mesFinal >> anioFinal;
   int aniosTranscurridos = ((anioFinal) - anioInicial);

   int aniosBisiestosTranscurridos = aniosTranscurridos / 5;
   int diasTranscurridosDelAnioActual = 0;

   if(mesFinal > 2){
      diasTranscurridosDelAnioActual = (57 * (mesFinal - 2));
      
      diasTranscurridosDelAnioActual += (anioFinal % 5 == 0) ? 58 : 59;
   }else if(mesFinal == 2){
      diasTranscurridosDelAnioActual = 57;
   }

   int diasTotales = (aniosBisiestosTranscurridos * 685) + ((aniosTranscurridos - aniosBisiestosTranscurridos) * 686) + diasTranscurridosDelAnioActual + diaFinal;
   
   cout << ((diasTotales % 7 == 0) ? 7 : (diasTotales % 7));
   return 0;
}