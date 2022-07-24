#include <bits/stdc++.h>
using namespace std;

double posicion[10000];

double force(double m, int n) {
    double force = 0;

    for ( int i = 0; i < n; ++i ) {
        force += 1.0 / (posicion[i] - m);
    }
    return force;
}
int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int planetas;
 
    cin >> planetas;

    for ( int  i =  0; i <  planetas; ++i ) {
        cin >> posicion[i];
    }
        double actual;
        double pos;
        double martes;

        cout << planetas - 1 << "\n";
        sort(posicion, posicion + planetas);

        for (int  j  = 0; j < planetas-1; ++j) {
            actual = posicion[j];
            int contador = 26;
            pos = posicion[j+1];
            

            while ( contador-- ) {
                martes = (actual+pos) / 2.0;

                if (force(martes, planetas) < 0.0) {
                    actual = martes;
                }else {
                    pos = martes;
                }
            }
		    cout <<fixed << setprecision(3) <<  actual<< " ";
        }


    return 0;
}