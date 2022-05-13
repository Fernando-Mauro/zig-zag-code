#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   vector <int> numeros (n-1);
   for(int i = 0; i < numeros.size(); i++){
      int temp; 
      cin >> temp;
      numeros[i] = temp;
   }
   sort(numeros.begin(), numeros.end());
   for(int i = 0; i < numeros.size(); i++){
      if(numeros[i] != (i + 1)){
         cout << i + 1;
         break;
      }
      if(i == (numeros.size() - 1)){
         cout << numeros.size() + 1 << endl;
      }
   }
}