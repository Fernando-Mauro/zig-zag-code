#include <iostream>

using namespace std;

int main() {
    int A, B, C, E, F, G, H, I, J;
    cin >> A;
    B = (A / 100) + 1;
    C = (( 3 * B ) / 4) - 12;
    E = (A % 19) + 1;
    F = ((( 8 * B ) + 5) / 25) - ( 5 + C);
    G = ((5 * A ) / 4 ) - ( C + 10);
    H = (( 11 * E ) + 20 + F) % 30;
    if ( H != 25)  {
        if ( H == 24) {
            H = H + 1;
        }
    }
    if ( E > 11 ) {
        H = H + 1; 
    }
    if ( H == 24 )  {
        H = H + 1;
    }
    I = 44 - H;
    if ( I < 21) {
        I = I + 30;
    }
    J = I + 7 - ((G + I) % 7);
    if ( J <= 31 ) {
        cout << J << " 3";
    } else {
        cout << J - 31 << " 4";
    }
    return 0;

}