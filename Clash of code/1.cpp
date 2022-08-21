#include <bits/stdc++.h>

using namespace std;

int main()
{
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   string cadena;
   getline(cin, cadena);
   string aux;
   if (cadena.size() >= 2)
   {
      for (int i = cadena.size() - 2; i < cadena.size(); ++i)
      {
         aux.push_back(cadena[i]);
      }
      int numero = stoi(aux);
      if (numero % 4 == 0)
      {
         cout << "AAAAAAAAAA!!!" << endl;
      }
      else
      {
         cout << "Ok" << endl;
      }
   }else{
      int numero = stoi(cadena);
      if (numero % 4 == 0)
      {
         cout << "AAAAAAAAAA!!!" << endl;
      }
      else
      {
         cout << "Ok" << endl;
      }
   }
   return 0;
}