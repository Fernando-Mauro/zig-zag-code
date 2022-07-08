#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int cantidad;
    stack<int> elementos;
    int first;
    int elemento;
    int sumaiguales = 0;
    int count = 1;

    cin >> cantidad;
    cin >> first;

    elementos.push(first);

    while( count < cantidad ) {
        cin >> elemento;
        int auxiliar = elementos.top();
        sumaiguales  = 0;
        if ( auxiliar == elemento ) {
            sumaiguales = elemento + auxiliar;
            elementos.pop();
            while(!elementos.empty()) {
                if (elementos.top() == sumaiguales ) {
                    sumaiguales += elementos.top();
                    elementos.pop();
                }else {
                    break;
                }
            }
            elementos.push(sumaiguales);
        }else {
            elementos.push(elemento);
        }
        count++;
    }

    cout << elementos.size() << endl;

    while(!elementos.empty()) {
        cout << elementos.top() << endl;
        elementos.pop();
    }


    return 0;
}