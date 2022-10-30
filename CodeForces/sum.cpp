// https://codeforces.com/problemset/problem/1742/A
#include <bits/stdc++.h>

using namespace std;

string solve(int a, int b, int c){
   if(a + b == c || a + c == b || c + b == a){
      return "YES";
   }   
   return "NO";
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int cases;
   cin >> cases;
   int a, b,c;
   while(cases--){
      cin >> a >> b >> c;
      cout << solve(a,b,c) << endl;
   }
   return 0;
}