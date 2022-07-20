#include <bits/stdc++.h>

using namespace std;

int main(){
    queue <int> temp;
    queue <int> cola;
    int vendidos = 0; 
    int accion;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
         cin >> accion;
         switch(accion){
             case 1:int news; cin >> news; cola.push(news); break;
             case 2:if(!cola.empty()){
                vendidos += cola.front();cola.pop();
             }break;
             case 3: temp.push(cola.size()); break;
             case 4: temp.push(vendidos); break;
         }
    }
    if(!temp.empty()){
        for(int i = 0; !temp.empty(); i++){
            cout << temp.front() << endl;
            temp.pop();
        }
    }
    return 0;
}