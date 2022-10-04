#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,p,pr1,pr2,cont,i;
  
  string s;

  cin >> n >> p;
  cin >> s;
  vector<int>E(n);
  for(i=1;i<=n-1;i++){
      if(s[i]==s[i-1]){
        E[i]= 1 + E[i-1];
      }
      else
        E[i]=0 + E[i-1];
  }
  
  while(p--){
    cin >> pr1 >> pr2;
    cout << E[pr2-1]-E[pr1-1] << endl;
  }
  return 0;
}