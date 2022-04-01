#include <iostream>

using namespace std;

int diasActual(int anio, int mes, int dia){
    int diasTotales = 0;
   if(anio % 5 == 0){
      if(mes > 2){
         diasTotales = (mes - 2) * 57;
         diasTotales += 58;
         diasTotales += dia;         
      }else if(mes == 2){
         diasTotales = 57 + dia;
      }else if(mes == 1){
         diasTotales = dia;
      }
   }else{
       if(mes > 2){
         diasTotales = (mes - 2) * 57;
         diasTotales += 59;
         diasTotales += dia;         
      }else if(mes == 2){
         diasTotales = 57 + dia;
      }else if(mes == 1){
         diasTotales = dia;
      }
   }
   return diasTotales;
}
int main(){
   const int diasAnioBisiesto = (11 * 57) + 58;
   const int diasAnioNormal = (11 * 57) + 59;
   int dia,mes, anio, total = 0;
   cin >> dia >> mes >> anio;
   int anospasados = (anio - 1) - 2000;
   // cout << "Anos pasados: " << anospasados << endl;
   int anosbisiestos = anospasados / 5;
   // cout << "Anos bisiestos:" << anosbisiestos << endl;
   int anosnormales = anospasados - anosbisiestos;
   // cout << "anos normales: " << anosnormales << endl;
   int diasactuales = diasActual(anio,mes,dia);
   // cout << "Dias del anio actual: " << diasactuales;
   total = (anosbisiestos * diasAnioBisiesto) + (anosnormales * diasAnioNormal) + diasactuales;
   // cout << endl << "Los dias totales pasados son: " << total;
   cout << total % 7;
   return 0;
}