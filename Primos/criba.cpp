#include <bits/stdc++.h>

using namespace std;

int main(){
    map <int, int> no_primos;
    long long min = 2, aux;
    int n;
    cin >> n;
    queue <int> numeros;
    int temp;
    long long max = 0;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        if(temp > max){
            max = temp;
        }
        numeros.push(temp);
    }
    while(min <= max){
        aux = min;
         if(no_primos.find(aux) == no_primos.end()){
             aux += min;
             while(aux <= max){
                 no_primos[aux] = aux;
                 aux += min;
             }
         }
         min++;
    }
    while(!numeros.empty()){
        if(no_primos.find(numeros.front()) != no_primos.end()){
            cout << "NO" << endl;
        }else{
            cout << "SI" << endl;
        }
        numeros.pop();
    }

    return 0;
}