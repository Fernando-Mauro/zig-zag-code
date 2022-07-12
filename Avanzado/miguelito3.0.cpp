// #https://omegaup.com/arena/problem/Miguelito-30/
#include <bits/stdc++.h>

using namespace std;

int main(){
   unsigned long long int a, b;
   cin >> a >> b;
   cout << floor(sqrt(b)) - ceil(sqrt(a)) + 1;
   return 0;
}