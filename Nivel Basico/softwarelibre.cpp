// https://omegaup.com/arena/problem/RedistribuyendoSoftwareLibre/
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n, number; 
   scanf("%d", &n);
   while (n--){
      scanf("%d", &number);
      if(number >= 3) printf("Ok\n");
      else printf("No\n");
   }
   return 0;
}