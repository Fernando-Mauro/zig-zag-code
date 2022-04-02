#include <iostream>

using namespace std;

int main()
{
   int n;
   cin >> n;
   int x = 1, y = n;
   for (int i = 0; i < n; ++i)
   {
      for (int j = 1; j <= n; ++j)
      {
         if (j == x)
         {
            cout << "@";
         }
         else if (j == y)
         {
            cout << "@";
         }
         else
         {
            cout << " ";
         }
      }
      x += 1;
      y -= 1;
      cout << endl;
   }
   return 0;
}