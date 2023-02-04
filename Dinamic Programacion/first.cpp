// Dada una lista de N números, determina la cantidad minima de elementos para obtener la suma K.

// Si existe más de una solución, cualquiera es válida.
// Límites

// N < 100
// Los elementos de la lista no serán mayores que 500
#include <bits/stdc++.h>

using namespace std;

struct nodo{
   int suma_actual;
   int cantidad;
   int posicion;
};

int solve(vector <int> &numeros, int &objetivo, nodo &actual){
   if(actual.suma_actual == objetivo) return actual.cantidad;
   if(actual.posicion > numeros.size()) return 0;
   solve(numeros,objetivo,)
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n;
   scanf("%d", &n);

   vector <int> numeros(n);
   for(int i = 0; i < n; ++i) scanf("%d", &numeros[i]);

   int objetivo;
   cin >> objetivo;

   nodo inicial = {0,0,0};
   cout << solve(numeros, objetivo, inicial);
   return 0;
}