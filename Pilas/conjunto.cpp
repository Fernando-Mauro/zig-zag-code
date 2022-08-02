// https://omegaup.com/arena/problem/Conjunto
#include <bits/stdc++.h>

using namespace std;

bool procesar(string cadena)
{
   stack<char> pila;
   for (int i = 0; i < cadena.size(); ++i)
   {
      if (cadena[i] != 'a' && cadena[i] != 'b' && cadena[i] != 'c' && cadena[i] != 'd' && cadena[i] != ')' && cadena[i] != '(')
      {
         return false;
      }
      if (cadena[i] == '(')
      {
         pila.push(cadena[i]);
      }
      else
      {
         if (cadena[i] == ')')
         {
            if (!pila.empty())
            {
               if (pila.top() != '(')
               {
                  return false;
               }
               else if (pila.top() == '(')
               {
                  pila.pop();
               }
            }else{
               return false;
            }
         }
      }
   }
   if (pila.empty())
   {
      return true;
   }
   return false;
}

int main()
{
   string cadena;
   cin >> cadena;
   if (procesar(cadena))
   {
      cout << 1;
   }
   else
   {
      cout << 0;
   }
   return 0;
}