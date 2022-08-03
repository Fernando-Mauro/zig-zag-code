//https://omegaup.com/arena/problem/L--OMI2010-Saltos/
#include <iostream>

using namespace std;

long long int mcd(long long int mayor, long long int menor){
   if(mayor % menor == 0){
      return menor;
   }else{
      long long int resto = mayor % menor;
      return mcd(menor, resto);
   }
}
long long int mcm(long long int a, long long int b){
   if(a > b){
      return (a * b) / mcd(a,b);
    }else{
      return (a * b) / mcd(b,a);
    }
}
int main(){
   long long int m,n,a,d,f,c;
   cin >> m >> n >> a >> d >> f >> c;
   long long int mcmHorizontal = mcm(n,d) / d;
   long long int mcmVertical = mcm(m,a) / a;
   long long int resultado = mcm(mcmHorizontal, mcmVertical);
   cout << resultado;
   return 0;
}