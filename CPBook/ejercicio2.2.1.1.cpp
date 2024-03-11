#include <bits/stdc++.h> 

using namespace std;

struct customTuple {
    int edad;
    string apellido;
    string nombre;
};

int main(){
    int n;
    cin >> n;
    vector <customTuple> elements(n);
    for(int i = 0; i < n; ++i){
        int edad;
        string apellido, nombre;
        cin >> edad;
        cin.ignore();
        getline(cin, apellido);
        cin.ignore();
        getline(cin, nombre);
        elements[i].edad = edad;
        elements[i].apellido = apellido;
        elements[i].nombre = nombre;
    }

    sort(elements.begin(), elements.end(), [](const customTuple a, const customTuple b){
        if(a.edad != b.edad){
            return a.edad < b.edad;
        }
        if(a.apellido != b.apellido){
            return a.apellido > b.apellido;
        }
        return a.nombre < b.nombre;
    });

    for(int i = 0; i < n; ++i){
        cout << "---------------------------\n";
        cout << "Edad: " << elements[i].edad << "\n";
        cout << "Apellido: " << elements[i].apellido << "\n";
        cout << "Nombre: " << elements[i].nombre << "\n"; 
    }
    return 0;
}