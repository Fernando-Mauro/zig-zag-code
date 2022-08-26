// https://omegaup.com/arena/problem/COMI-Adivina-el-numero
#include "AdivinaElNumero.h"
#include <iostream>

using namespace std;
// Main
//	long long pista(long long x)

void adivina(long long a, long long b) {
	// FIXM
	while(a <= b){
	    long long int mitad = a + (b - a) / 2;
        cout << mitad << endl;
        long long int resultado = pista(mitad);
        if(resultado == 0){
            return;
        }
        if(resultado < 0){
            b = mitad -1;
        }
        if(resultado == 1){
            a = mitad + 1;
        }
	}
    // hola
}