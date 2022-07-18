#include <bits/stdc++.h>
using namespace std;

typedef long long int bt64;

int main() {

    int posicion;
    int cuadritos = 0;
    
    int actual = 1;
    
    cin >> posicion;

    int vertical = (posicion * 2)-1;

    while (actual < vertical)  {
        cuadritos+= actual;
        actual+=2;
    }
    while (actual > 1 ) {
        actual-=2;
        cuadritos+= actual;
    }

    cout  << cuadritos + vertical << endl;

    return 0;
}