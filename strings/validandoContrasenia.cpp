// https://omegaup.com/arena/problem/Validando-contrasena/
#include <iostream>
#include <string>
using namespace std;

bool validarContraseña(string &contrasena){
   bool alfanumerico = true;
   bool minuscula = false, mayuscula = false, longitud = false, numero = false;
   /* ascci code
   48 - 57 is number
   65 - 90 is capital
   97 - 122 lower case
   */
   //comprobar longitud
   if(contrasena.size() > 5 && contrasena.size() < 33){
      longitud = true;
   }else{
      return false;
   }
   //comenzar a recorrer el string
   for(int i = 0; i < contrasena.size(); ++i){
      if(alfanumerico){
         if(contrasena[i] >= 48 && contrasena[i] <= 57 || contrasena[i] >= 65 && contrasena[i]<= 90 || contrasena[i] >= 97 && contrasena[i] <= 122){
            if(contrasena[i] >= 65 && contrasena[i]<= 90){
               mayuscula = true;
            }
            if(contrasena[i] >= 48 && contrasena[i] <= 57){
               numero = true;
            }
            if(contrasena[i] >= 97 && contrasena[i] <= 122){
               minuscula = true;
            }

         }else{
            return false;
         }
      }else{
         return false;
      }
   }
   if(alfanumerico && minuscula && mayuscula &&longitud && numero){
      return true;
   }
   return false;
}
int main()
{
   string contrasena;
   int n;
   cin >> n;
   cin.ignore();
   while(n--){
      getline(cin,contrasena);
      if(validarContraseña(contrasena)){
         cout << contrasena << ": " << "Valido" << endl;
      }else{
         cout << contrasena << ": " << "Invalido" << endl;
      }
   }
   return 0;
}