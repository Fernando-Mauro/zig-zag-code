#include <iostream> 
#include <string>
#include <map>

using namespace std; 

bool comprobar(string &first, string &second){
   map <char,int> cuenta1;
   map <char,int> cuenta2;
   for(int i = 0; i < first.length(); i++){
      char caracter = first[i];
      if(cuenta1.find(caracter) != cuenta1.end()){
         cuenta1.find(caracter) -> second++;
      }else{
         cuenta1.insert(pair <char, int> (caracter,1));
      }
   }
   for(int i = 0; i < second.length(); i++){
      char caracter = second[i];
      if(cuenta2.find(caracter) != cuenta2.end()){
         cuenta2.find(caracter) -> second++;
      }else{
         cuenta2.insert(pair <char, int> (caracter,1));
      }
   }
   for(auto el : cuenta1 ){
      if(cuenta2.find(el.first) !=cuenta2.end()){  
         int cantidad = cuenta2.find(el.first) -> second;
         if(cantidad != el.second){
            return false;
         }
      }else{
         return false;
      }
   }
   return true;
}
int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   string first, second;
   cin >> first >> second;
   if(first.length() == second.length()){
     if(comprobar(first, second)){
        cout << "SI es un ANAGRAMA!";
     }else{
        cout << "NO es un Anagrama!";
     }
   }else{
      cout << "Las cadenas tienen longitud diferente." << endl << "Operacion Cancelada!";
   }
   return 0;
}