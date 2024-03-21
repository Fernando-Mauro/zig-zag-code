#include <bits/stdc++.h> 

using namespace std;

typedef vector <vector <int>> matriz;


int neighborsX[4] = {0, -1, 1, 0};
int neighborsY[4] = {-1, 0, 0, 1};

struct Coord{
    int x;
    int y;

    bool operator==(const Coord &rhs)const {
        return rhs.x == x && rhs.y == y;
    }
};

struct Node {
    Coord point;
    int weigth;

    bool operator<(const Node &rhs)const {
        return rhs.weigth < weigth;
    }
};

int solve(matriz &map, Coord inicio, Coord fin){
    priority_queue <Node> nodes;
    
    Node firstNode;
    firstNode.point = inicio;
    firstNode.weigth = 0;

    matriz visitados (map[0].size(),vector <int> (map.size(), 0));
    nodes.push(firstNode);
    
    visitados[inicio.x][inicio.y] = 1;
    
    while(!nodes.empty()){
        // Sacar al primer nodo
        Node current = nodes.top();

        nodes.pop();

        // Verificar que no hemos llegado al final 
        if(current.point == fin ){
            return current.weigth;
        }
        // visitar a los adyacentes :D
        for(int i = 0; i < 4; ++i){
            Coord neighbor;
            neighbor.x = current.point.x + neighborsX[i];
            neighbor.y = current.point.y + neighborsY[i];
            
            // Comprobar que sigan dentro de los limites
            if(neighbor.x > (map.size() - 1) || neighbor.x < 1 || neighbor.y > (map[0].size() - 1) || neighbor.y < 1 )
                continue;

            // Comprobar que no se haya visitado
            if(visitados[neighbor.x][neighbor.y])
                continue; 
            // Comprobar que sea un bloque valido
            if(map[neighbor.x][neighbor.y] == -1)
                continue;
            
            Node newNode;
            newNode.point = neighbor;
            newNode.weigth = (current.weigth + map[neighbor.x][neighbor.y]) + 1;  
            visitados[neighbor.x][neighbor.y] = 1;
            nodes.push(newNode);
        }
    }
    return -1;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    Coord inicio, fin;
    cin >> inicio.x >> inicio.y;
    cin >> fin.x >> fin.y;
    matriz map(n + 1, vector <int> (m + 1, 0));
    
    for(int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; j++){
            char aux;
            cin >> aux;
            if( aux == '#'){
                map[i][j] = -1;
                continue;
            }

            if(aux == '.'){
                map[i][j] = 0;
                continue;
            }

            map[i][j] = aux - '0';
        }
    }


    cout << solve( map, inicio, fin);
    return 0;
}