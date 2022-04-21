#include <iostream>

using namespace std;

int modificaciones = 0;
int reducir(int numero){
   if(numero %2 == 0){
      modificaciones++;
      numero/=2;
   }else{
      modificaciones++;      
      numero++;
   }
   //segundo proceso
   if(numero >= 100){
      modificaciones++;
      numero /= 100;
   }else if(numero < 100 && numero >= 10){
      numero /= 10;
      modificaciones++;
   }
   //tercer proceso
   if(numero % 3 == 0){
      numero--;
      modificaciones++;
   }
   return numero;
}
int main(){
   int n;
   cin >> n;
   n = reducir(n);
   cout << n << " " << modificaciones;
   return 0;
}