#include<bits/stdc++.h>
using namespace std;

int main() {

    long double operando1;
    char operador;
    long double operando2;

    cin >> operando1 >> operador >> operando2;

    if ( operador == '+' ) {
        long double suma = operando1+operando2;
         cout << fixed << setprecision(2) << suma << endl;
    }
    else if ( operador == '-' ) {
        long double resta = operando1-operando2;
         cout << fixed << setprecision(2) << resta << endl;
    }
    else if ( operador == '*' ) {
        long double mul = operando1*operando2;
         cout << fixed << setprecision(2) << mul << endl;
    }
    else if ( operador == '/' ) {
       float div = operando1 / operando2;
        cout << fixed << setprecision(2) << div << endl;
    }else {
        cout << "Operación no disponible" << endl;
    }

    return 0;
}