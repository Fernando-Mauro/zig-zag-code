#include <bits/stdc++.h>

using namespace std;

int main()
{
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);

   int t;
   cin >> t;
   vector<char> digits(t);

   for (int i = 0; i < t; ++i)
   {
      cin >> digits[i];
   }

   sort(digits.begin(), digits.end());
   for (int i = 0; i < t; ++i)
   {
      cout << digits[i] << " ";
   }

   return 0;
}