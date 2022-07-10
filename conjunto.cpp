//https://omegaup.com/arena/problem/Conjunto
#include <bits/stdc++.h>

using namespace std;

bool validito(string &labrujita){
   stack<char> pila;

   for (int i = 0; i < labrujita.size(); ++i){
      if (labrujita[i] != 'a' && labrujita[i] != 'b' && labrujita[i] != 'c' && labrujita[i] != 'd' && labrujita[i] != ')' && labrujita[i] != '('){
         return false;
      }
      if (labrujita[i] == '('){
         pila.push(labrujita[i]);
      }else{
         if (labrujita[i] == ')'){
            if (!pila.empty()){
               if (pila.top() != '('){
                  return false;
               }else if (pila.top() == '('){
                  pila.pop();
               }
            }else{
               return false;
            }
         }
      }
   }
   
   if (pila.empty()){
      return true;
   }
   return false;
}

int main(){

   string bontia;
   
   getline(cin, bontia);

   if (validito(bontia)){
      cout << 1 << "\n";
   }else{
      cout << 0 << "\n";
   }

   return 0;
}