#include <iostream>

using namespace std;

int main(){
    int numero = 0;
    cin >> numero;
    //      Condicion
    //                         Verdadero
                                        // Falso
    
    string respuesta = (numero % 2 == 0) ? "Par" : "Impar"; 
    cout << respuesta;
    return 0;
}