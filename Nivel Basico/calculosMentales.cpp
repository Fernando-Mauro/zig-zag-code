#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    double r;
    cin >> r;
    
    double copia = r;
    cout << fixed << setprecision(10) << r << " ";
    // Paso 1: sumar 5 a R
    r += 5;
    cout << fixed << setprecision(10) << r<< " ";

    // Paso 2: elevar al cuadrado
    r = pow(r,2);
    cout << fixed << setprecision(10) << r<< " ";

    // Paso 3 dividir por el original
    r = r / (copia / 3);
    cout << fixed << setprecision(10) << r<< " ";

    // Paso 4 cubo
    r = pow(r,3);
    cout << fixed << setprecision(10) << r<< " ";

}