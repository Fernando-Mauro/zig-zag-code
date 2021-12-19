#include <bits/stdc++.h>

using namespace std;

int main()
{
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   while (n != 0 && m != 0)
   {
      set<int> primero;
      set<int> segundo;
      int basura;
      int contador = 0;
      int aux;
      for (int i = 0; i < n; ++i)
      {
         cin >> aux;
         primero.insert(aux);
      }
      for (int i = 0; i < m; ++i)
      {
         cin >> aux;
         segundo.insert(aux);
      }
      cin >> n >> m;
      if (n > m)
      {
         for (auto element : primero)
         {
            int valor = element;
            if (segundo.find(valor) != segundo.end())
            {
               contador++;
            }
         }
      }
      else
      {
         for (auto element : segundo)
         {
            int valor = element;
            if (primero.find(valor) != primero.end())
            {
               contador++;
            }
         }
      }
      cout << contador << endl;
   }
   return 0;
}