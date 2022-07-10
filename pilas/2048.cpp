// https://omegaup.com/arena/problem/A-jugar-2048
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >>n;
    int aux;
    stack <int> pila;
    while(n--){
        cin >> aux;
        int topElement = aux;
        int popElement = pila.empty() ? -1: pila.top();
        while(topElement == popElement){
            int sum = topElement + popElement;
            pila.pop();
            pila.push(sum);
            topElement = pila.empty() ? 0 : pila.top();
            pila.pop();
            popElement = pila.empty()? -1: pila.top();
        }
        pila.push(topElement);

    }
    cout << pila.size() << endl;
    while(!pila.empty()){
        cout << pila.top() << endl;
        pila.pop();
    }
    return 0;
}