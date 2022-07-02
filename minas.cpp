// https://omegaup.com/arena/problem/Minas/
/* solucion que da 92 puntos con tiempo limite excedido" */
#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    char aux;
    for(int i = 0; i< n; ++i){
        for(int j = 0; j < m ; ++j){
            cin >> aux; 
            if(aux == '*'){
               cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    return 0;
}
