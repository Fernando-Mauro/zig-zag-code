// https://codeforces.com/contest/4/problem/C
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   map <string, int> palabras;
   while(n--){
      string word ;
      cin >> word;
      palabras[word]++;
      if(palabras[word] == 1){
         cout << "OK" << endl;
      }else{
         cout << word << palabras[word] - 1 << endl;
      }
   }
   return 0;
}