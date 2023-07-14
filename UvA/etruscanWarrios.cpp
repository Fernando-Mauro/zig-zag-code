#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int cases;
    scanf("%d", &cases);
    while(cases--){
      long long n;
      scanf("%ld", &n);
      long long answer = ((-1+sqrt(1 + 8*n))/2);
      printf("%ld\n", answer);  
    }
    return 0;
}