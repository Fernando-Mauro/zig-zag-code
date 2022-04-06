#include <iostream>

using namespace std;

int main(){
   int primero, segundo, tercero;
   for(int c = 1; c < 1000; c++){
      for(int b = 1; b < 1000; b++){
         for(int a = 1; a < 1000; a++){
            if(a + b + c == 1000){
               if((a * a) + (b * b) == (c * c)){
                  primero = a;
                  segundo = b;
                  tercero = c;
                  break;
               }
            }
         }
      }
   }
   cout << primero * segundo * tercero;
   return 0;
}