#include <bits/stdc++.h>

using namespace std;

struct Nino{
    string nombre;
    int peso;
    float estatura;
};

bool customSort(const Nino a, const Nino b){
    
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    // vas a recibir n niños, y por cada niño vas a tener su nombre, su peso y su estatura
    // Ordenar a los niños primero por nombre, si hay dos niños con el mismo nombre, por peso (de menor a mayor) y despues por estatura de mayor a menor

    int n;
    vector <Nino> ninos;
    // (juanito < fernando)

    cin >> n;
    while(n--){
        int peso;
        float estatura;
        string nombre;
        cin >> nombre >> peso >> estatura;
        Nino actual = {nombre, peso, estatura};
        ninos.push_back(actual); 
    }

    sort(ninos.begin(), ninos.end(), customSort);
    
    for(int i = 0; i < ninos.size(); ++i){
        cout << ninos[i].nombre << " " << ninos[i].peso << " " << ninos[i].estatura << "\n";
    }
    return 0;
}