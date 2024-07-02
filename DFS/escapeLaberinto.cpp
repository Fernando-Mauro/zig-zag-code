#include <bits/stdc++.h> 

using namespace std;

typedef vector <vector <char>> matriz;

struct Node{
    int x;
    int y;
};

Node entrada = {-1, -1};
Node salida = {-1, -1};

vector <int> vecinosX = {-1, +1, 0, 0};
vector <int> vecinosY = {0, 0, +1, -1};

// Bandera
bool haySalida = false; 

// Paso por referencia
// f(int &x) x += 1 -> int a = 10; f(a); cout << a << endl; a = 11
// f(int x) x += 1 -> int a = 10; f(a); cout << a << endl; a = 10
 
void dfs(matriz &laberinto, vector <vector <bool>> &visitados){

    stack <Node> pila;
    pila.push(entrada);

    while(!pila.empty()){
        Node actual = pila.top();
        pila.pop();

        // Agregar vecinos, norte, sur este y oeste
        for(int i = 0; i < 4; ++i){
           int nuevaX = actual.x + vecinosX[i]; 
           int nuevaY = actual.y + vecinosY[i];

            // Checar limites 
            if(!(nuevaX < laberinto.size() && (nuevaY < laberinto[0].size()) && nuevaY >= 0 && nuevaX >= 0))
                continue;

            // Si ya visite el nodo actual continuo
            if(visitados[nuevaX][nuevaY])
                continue;
            // Checar que el vecino sea un espacio
            
            // 'S'
            if(laberinto[nuevaX][nuevaY] == 'S'){
                haySalida = true;
                return;
            }

            if(laberinto[nuevaX][nuevaY] != ' ')
                continue;
            
            visitados[nuevaX][nuevaY] = true;
            
            Node vecino = {nuevaX, nuevaY};
            pila.push(vecino);
        }
    }

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    matriz laberinto(n, vector <char> (m));
    vector <vector <bool>> visitados(n, vector <bool> (m,false));

    cin.ignore();

    for(int i = 0; i < n; ++i){
        string temp;
        getline(cin, temp);
        for(int j = 0; j < temp.size(); j++){
            laberinto[i][j] = temp[j];
            if(laberinto[i][j] == 'E'){
                entrada.x = i;
                entrada.y = j; 
            }

            if(laberinto[i][j] == 'S'){
                salida.x = i;
                salida.y = j; 
            }
        }
    }

    dfs(laberinto, visitados);

    cout << ((haySalida) ? "Si": "No") << "\n";
    return 0;
}