// Dada una lista de N números, determina la cantidad minima de elementos para obtener la suma K.

// Si existe más de una solución, cualquiera es válida.
// Límites

// N < 100
// Los elementos de la lista no serán mayores que 500
#include <bits/stdc++.h>

using namespace std;

int minimo = INT_MAX;

int solve(vector <int> &numeros, int objetivo, int indice, int sumaActual, int elementos){
   if(sumaActual == objetivo) minimo = min(minimo, elementos);
   
   if(indice > numeros.size()) return 0;

   solve(numeros, objetivo, indice + 1, sumaActual + numeros[indice], elementos + 1);

   solve(numeros, objetivo, indice + 1, sumaActual, elementos);
}

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   
   vector <int> numeros = {2,1,8,13,5,7,5};
   int k = 11;
   
   solve(numeros, k, 0, 0, 0);
   cout << minimo << endl;
   return 0;
}