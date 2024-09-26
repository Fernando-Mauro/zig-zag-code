// https://omegaup.com/arena/problem/Escape-del-laberinto/
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> Matriz;

struct Node{
    int x;
    int y;
};

Node inicio;
Node salida;

vector <int> vecinosX = {-1, 0, 1, 0};
vector <int> vecinosY = {0, 1, 0, -1};

string BFS(Matriz &mapa, vector <vector <bool>> &visitados){
    // BFS OCUPA COLA
    stack <Node> adj;
    // El primer paso es agregar el nodo inicial a la cola
    adj.push(inicio);

    // El segundo paso es vaciar la cola con un while
    while(!adj.empty()){
        // El tercer paso es sacar al front de la cola
        Node actual = adj.top();
        adj.pop();

        if(mapa[actual.x][actual.y] == 'S')
            return "Si";
        visitados[actual.x][actual.y] = true;
        // Cuarto paso es visitar a los vecinos del actual
        for(int i = 0; i < 4; ++i){
            int nuevaCordX = actual.x + vecinosX[i];
            int nuevaCordY = actual.y + vecinosY[i];
            // VERIFICAR QUE SEA UNA COORDENADA VALIDA(QUE NO SEA UN #, QUE NO ESTE VISITADA, O QUE NO NOS SALGAMOS DE LA MATRIZ)
            if(nuevaCordX >= 0 && nuevaCordY >= 0 && nuevaCordX < mapa.size() && nuevaCordY < mapa[0].size() && mapa[nuevaCordX][nuevaCordY] != '#' && !visitados[nuevaCordX][nuevaCordY]){
                // Aqui entramos si todo esta bien
                Node nuevoNodo;
                nuevoNodo.x = nuevaCordX;
                nuevoNodo.y = nuevaCordY;
                adj.push(nuevoNodo);
            }
        }

    }
    return "No";
}
int main() {
    int n , m;
    cin >> n >> m;

    Matriz mapa(n, vector <char> (m));
    vector <vector <bool>> visitados(n, vector <bool> (m, false));

    cin.ignore();
    for(int i = 0; i < n; ++i){
        string temp;
        getline(cin, temp);
        for (int j = 0; j < m; ++j){
            mapa[i][j] = temp[j];
            if(temp[j] == 'E'){
                inicio.x = i;
                inicio.y = j;
            }
            if(temp[j] == 'S'){
                salida.x = i;
                salida.y = j;
            }
        }
    }

    cout << BFS(mapa, visitados);
    return 0;
}