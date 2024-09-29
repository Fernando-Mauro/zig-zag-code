#include <bits/stdc++.h> 

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<char, vector<char>> teclas;

    teclas['1'] = {'1', '.'};
    teclas['2'] = {'2', 'A', 'B', 'C'};
    teclas['3'] = {'3', 'D', 'E', 'F'};
    teclas['4'] = {'4', 'G', 'H', 'I'};
    teclas['5'] = {'5', 'J', 'K', 'L'};
    teclas['6'] = {'6', 'M', 'N', 'O'};
    teclas['7'] = {'7', 'P', 'Q', 'R', 'S'};
    teclas['8'] = {'8', 'T', 'U', 'V'};
    teclas['9'] = {'9', 'W', 'X', 'Y', 'Z'};
    teclas['0'] = {'0', ' '};

    string cadena;
    getline(cin, cadena);

    if (cadena.empty()) {
        return 0;
    }

    char anterior = cadena[0];
    int repeticiones = 1;

    for (int i = 1; i < cadena.size(); ++i) {
        if (cadena[i] == '#') {
            cout << teclas[anterior][repeticiones % teclas[anterior].size()];
            if (i + 1 < cadena.size()) {
                anterior = cadena[i + 1];
                repeticiones = 1;
                i++;
            }
            continue;
        }
        if (cadena[i] == ' ') {
            cout << teclas[anterior][repeticiones % teclas[anterior].size()];
            if (i + 1 < cadena.size()) {
                anterior = cadena[i + 1];
                repeticiones = 1;
                i++;
            }
            continue;
        }
        if (cadena[i] == anterior) {
            repeticiones++;
        } else {
            cout << teclas[anterior][repeticiones % teclas[anterior].size()];
            anterior = cadena[i];
            repeticiones = 1;
        }
    }

    cout << teclas[anterior][repeticiones % teclas[anterior].size()];

    return 0;
}
