// https://omegaup.com/arena/problem/Escape-del-laberinto/
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char> > Matriz;

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

bool busqueda(Matriz &laberinto, int i, int j, Matriz &solucion) {
  
  char posActual = laberinto[i][j];

  if (posActual == 'S') {
    return true;
  }

  for (int k = 0; k < 4; k++) {
    int nx = i + fils[k];
    int ny = j + cols[k];
    bool noSaleMatriz = (nx >= 0 && nx < laberinto.size() && ny >= 0 && ny < laberinto[nx].size());

    if (noSaleMatriz && laberinto[nx][ny] != '#' && solucion[nx][ny] == ' ') {
      solucion[nx][ny] = '#';
      if (busqueda(laberinto, nx, ny, solucion)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int filas, columnas;
  cin>>filas>>columnas;
  cin.ignore();

  Matriz laberinto = Matriz(filas, vector<char>(columnas, ' '));
  Matriz solucion = Matriz(filas, vector<char>(columnas, ' '));
  
  for (int i=0; i<filas; i++) {
    string s;
    getline(cin,s);
    for (int j=0; j<s.size(); j++) {
      laberinto[i][j] = s[j];
    }
  }

  bool tieneSalida = false;
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      if (laberinto[i][j] == 'E') {
        solucion[i][j] = '#';
        tieneSalida = busqueda(laberinto, i, j, solucion);
        break;
      }
    }
  }

  if (tieneSalida) {
    cout<<"Si"<<endl;
  } else {
    cout<<"No"<<endl;
  }

  return 0;
}