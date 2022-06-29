// https://omegaup.com/arena/problem/Freddy-y-el-CR
#include <bits/stdc++.h>

using namespace std;

int main(){
   map <string, int> participantes;
   int n;
   cin >> n;
   string name;
   int puntaje;
   while(n--){
      cin.ignore();
      getline(cin, name);
      cin >> puntaje;
      participantes.insert(pair <string, int> (name, puntaje));   
   }
   cin.ignore();
   getline(cin, name);
   auto el = participantes.find(name);
   cout << el -> second;
   return 0;
}