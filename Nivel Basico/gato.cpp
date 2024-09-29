#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int gato1 = 0, gato2 = 0, raton = 0;
    cin >> gato1 >> gato2 >> raton;

    // Proceso
    int distanciaG1 = abs(raton - gato1);
    int distanciaG2 = abs(raton - gato2);

    if(distanciaG1 < distanciaG2){
        cout << "gato A";
    }

    if(distanciaG1 == distanciaG2){
        cout << "raton C";
    }
    
    if(distanciaG2 < distanciaG1){
        cout << "gato B";
    }

    return 0;
}