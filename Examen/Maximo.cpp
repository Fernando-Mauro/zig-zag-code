#include  <bits/stdc++.h>
using namespace std;

stack<int> pila;

void agregar(int neymar){
    pila.push(neymar);
}
void borrar() {
    pila.pop();
}
int main() {

    int Cantidad_preguntas;
    int maximo = 0;
    int actual;
    
    map<int, int> mapita;

    cin >> Cantidad_preguntas;
    for(int i =  0; i < Cantidad_preguntas; ++i) {
        int pregunta;
        cin >> pregunta;
        if(pregunta == 1) {
            cin >> actual;
            agregar(actual);

            if (mapita.find(actual) == mapita.end())  {
                mapita[actual] = 0;
            }
            mapita[actual]++;
        }
        else if ( pregunta == 2 ) {
            actual = pila.top();
            borrar();
            mapita[actual]--;

            if(mapita[actual] == 0) {
                mapita.erase(actual);
            }
        }else {
            cout << mapita.rbegin()->first <<  endl;
        }
    }
    return 0;
}