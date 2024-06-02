
#include <bits/stdc++.h> 

using namespace std;

vector <int> primero(4);
vector <int> segundo(4);
vector <int> tercero(3);


int total = 0;
int suma = 0;

set <int> sumas;
bool comprobar(){
    int first = 0, second = 0, third = 0;
    for(int i = 0; i < primero.size(); ++i){
        first += primero[i];
    }

    for(int i = 0; i < segundo.size(); ++i){
        second += segundo[i];
    }

    for(int i = 0; i < tercero.size(); ++i){
        third += tercero[i];
    }

    if(first == second && first == third ){
        return true;
    }
    return false;
}

void combinacion(vector<int>& numeros){
    sort(numeros.begin(), numeros.end());
    do {
        primero[0] = numeros[0];
        primero[1] = numeros[1];
        primero[2] = numeros[2];
        primero[3] = numeros[3];
        segundo[0] = numeros[3];
        segundo[1] = numeros[4];
        segundo[2] = numeros[5];
        segundo[3] = numeros[6];
        tercero[0] = numeros[0];
        tercero[1] = numeros[7];
        tercero[2] = numeros[6];

        if(comprobar()){
            total++;
            
            int first = 0;
            for(int i = 0; i < primero.size(); ++i){
                first += primero[i];
            }

            sumas.insert(first);
            for(int i = 0; i < 4; ++i){
                cout << primero[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < 4; ++i){
                cout << segundo[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < 3; ++i){
                cout << tercero[i] << " ";
            }
            cout << endl << "----" << endl;
        }
    } while(next_permutation(numeros.begin(), numeros.end()));
}

int main(){
    vector<int> numeros = {1,2,3,4,5,6,7,8};
    combinacion(numeros);
    cout << "El total es:" << total << endl;
    for(auto it:sumas){
        cout << it << endl;
    }
    return 0;
}
