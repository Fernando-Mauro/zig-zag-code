// https://omegaup.com/arena/problem/Calculadora-de-salario-UAMA-PE/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int horas;
   double salario;
   cin >> horas >> salario;
   double total = 0;
   if(horas <= 40){
      total += salario * horas;
   }else if(horas > 40 && horas <= 50){
      total += (horas - 40) * (salario * 1.5);
      total += 40 * salario;
}else if(horas > 50){
   total += 40 * salario;
   total += 10 * (salario * 1.5);
   total += (horas - 50) * (salario * 2);
}
cout << total << endl;
return 0;
}