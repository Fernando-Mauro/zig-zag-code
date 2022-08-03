// https://omegaup.com/arena/problem/Ordenamiento-Alfabetico
#include <bits/stdc++.h>

using namespace std;

bool ordenar(string &first_node, string &second_node){
   int apuntador = 0;
   while(apuntador != first_node.size() && apuntador != second_node.size()){   
      bool isUpperFirst = isupper(first_node[apuntador]);
      bool isUpperSecond = isupper(second_node[apuntador]);
      first_node[apuntador] = isUpperFirst ? tolower(first_node[apuntador]) : first_node[apuntador];
      second_node[apuntador] = isUpperSecond ? tolower(second_node[apuntador]) : second_node[apuntador];
      int asc_first = int(first_node[apuntador]);
      int asc_second = int(second_node[apuntador]);
      if(asc_first == asc_second){
          if(isUpperFirst){
            first_node[apuntador] = toupper(first_node[apuntador]);
         }
         if(isUpperSecond){
            second_node[apuntador] = toupper(second_node[apuntador]);
         }
         apuntador++;
         continue;
      }
      if(asc_first < asc_second){
         if(isUpperFirst){
            first_node[apuntador] = toupper(first_node[apuntador]);
         }
         if(isUpperSecond){
            second_node[apuntador] = toupper(second_node[apuntador]);
         }
         return true;
      }
      if(asc_second < asc_first){
         if(isUpperFirst){
            first_node[apuntador] = toupper(first_node[apuntador]);
         }
         if(isUpperSecond){
            second_node[apuntador] = toupper(second_node[apuntador]);
         }
         return false;
      }
   }
}
int main(){
   int n;
   cin >> n;
   vector <string> nombres(n);
   for(int i = 0; i < n; i++){
      cin >> nombres[i];
   }
   sort(nombres.begin(), nombres.end(), ordenar);

   for(int i = 0; i < n; i++){
      cout << nombres[i] << endl;
   }
   return 0;   
}