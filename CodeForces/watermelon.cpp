// https://codeforces.com/problemset/problem/4/A
#include <bits/stdc++.h>

using namespace std;

int main(){
   // aadd a comment
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int num;
   cin >> num;
   if(num % 2 == 0 && num > 2){
      cout << "YES" << endl;
      return 0;
   }else{
      cout << "NO" << endl;
   }
   return 0;
}