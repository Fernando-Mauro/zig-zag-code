#include <iostream>

using namespace std;

int main(){
   int n;
   cin >> n;
   int inicial =1, final =n;
   bool principio = true, fin = false;
   for(int i = 1; i <= (n / 2)+1; i++){
      if(inicial == final){
         cout << inicial << " ";
         break;
      }
      if(principio){
         cout << inicial << " " << final << " ";
         inicial += 1;
         final -= 1;
         fin = true;
         principio = false;
      }else if(fin){
         cout << final << " " << inicial << " ";
         inicial += 1;
         final -= 1;
         fin = false;
         principio = true;
      }
   }
   return 0;
}