#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    int cantidad;
    char carc;
    int inicio, fin;
    bool existente = false;

    cin >> s;
    cin >> cantidad;

    for ( int i = 0; i < cantidad; ++i) {
        cin  >> carc >> inicio >> fin;

        for( int j = 0; j < fin; ++j ) {
            if ( s[inicio] == carc ) {
                existente = true;
                cout << 1 << "\n";
                break;
            }else {
                existente = false;
            }
            inicio++;
        }
        if ( !existente ) {
            cout << 0 << "\n";
        }
    }
    return 0;
}