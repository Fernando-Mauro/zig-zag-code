#include <iostream>

using namespace std;

int main(){
   int l ;
   cin >> l;
   if(l >= 0 && l <= 3){
      cout << "BEBE";
   }else if(l >= 4 && l <= 14){
      cout << "NINO";
   }else if(l >= 15 && l <= 18){
      cout << "JOVEN";
   }else if(l >=19 && l <=65){
      cout << "ADULTO";
   }else{
      cout << "ADULTO 3RA";
   }
   return 0;
}