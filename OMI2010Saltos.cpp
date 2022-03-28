#include <iostream>

using namespace std;

int mcd(int a , int b){
   while(a != 0 && b != 0){
      if(a > b){
         a = a % b;
      }else{
         b = b % a;
      }
   }
   if( a == 0){
      return b;
   }else{
      return a;
   }
}
int mcm(int a, int b){
   int auxiliar = 0;
   if( a > b){
      auxiliar = a / mcd(a,b);
      return b * auxiliar;
   }else{
      auxiliar = b / mcd(a,b);
      return b * auxiliar;
   }
}
int main(){
   cout << mcm(3,5) / 5;
   return 0;
}