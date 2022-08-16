# Acomoda el Numero
## Link: 
> https://omegaup.com/arena/problem/AcomodandoOMI/#problems
<br>

Tienes una lista desordenada con  números distintos los cuales tienen valores entre  y . Llamemos al primer número de esta lista . Debes ordenar los números de la lista y ver en qué posición queda el número . En este problema la primera posición de la lista es la posición  y la última es la posición.

### **Problema**

Escribe un programa que dada la lista de _N_ números determine en qué posición queda el elemento  (el primero de la lista) después que ésta se ordena.

### **Entrada**

Tu programa debe leer del teclado la siguiente información:

   * En la primera línea el número entero , la cantidad de números en la  lista.
   * En la segunda línea los  números de la lista separados cada uno por un espacio.

### **Salida**

Tu programa debe escribir en la pantalla un único número entero que representa la posición final del elemento $a_0$  en la lista ordenada.

### **Restricciones**

*1 < N $\leq$ 2,000,000*

*0 $\leq$ M $\leq$ $10^9$*

### **Ejemplo**

| Entrada | Salida | Descripción |
| --- | --- | --- |
| 5 <br> 14 2 1 17 23  | 2 | Recuerda que las posiciones de la lista se cuentan a partir de **0** . La lista ordenada queda **1,2,14,17,23**, de modo que **14**, que era el primer elemento en la lista desordenada, quedó en la posición **2**. |

## **Solución**

1. Solución fácil:
   * A simple vista podríamos considerar guardar todos los números en un arreglo y después de almacenarlos ordenarlos, una vez ordenados buscar el numero dentro de el arreglo, (búsqueda linear, binaria, etc...). Quedaría mas o menos asi:
      ```cpp
         #include <iostream>
         #include <vector>
         #include <algorithm>

         using namespace std;

         int main(){
            long long n; 
            cin >> n;
            vector <long long> numeros(n);
            for(int i = 0; i < n; i++){
               cin >> numeros[i];
            }
            long auxiliar = numeros[0];
            sort(numeros.begin(), numeros.end());
            for(int i = 0; i < n; i++){
               if(numeros[i] == auxiliar){
                  cout << i ;
                  break;
               }
            }
         }
      ```
      Con esta solución obtendríamos un puntaje parcial ya que guardar todos los elementos, y posteriormente ordenarlos nos toma mucho tiempo y ademas mucha memoria.
   
2. Solución Optima:
   * SI analizamos un poco mas el problema podremos llegar a la conclusion de que solo necesitamos contar cuantos elementos del arreglo son menores que el elemento $a_0$, asi podremos darnos cuanta que con un while y un if quedaría el problema resulto, como se muestra a continuación: 
      ```cpp
         // https://omegaup.com/arena/problem/AcomodandoOMI/
         #include <bits/stdc++.h>

         using namespace std;

         int main(){
            cin.tie(nullptr);
            ios_base::sync_with_stdio(false);
            int n;
            cin >> n;
            int numero;
            cin >> numero;
            int aux;
            int pos = 0;
            //Le quitamos 1 a n porque ya guardamos el numero en la posicion 0
            n -= 1;
            while(n--){
               cin >> aux;
               if(aux < numero) pos++;
            }
            cout << pos << endl;
            return 0;
         }
      ```
      Con esta optimización el problema ocuparía menos memoria y tiempo, asi obtendríamos los 100 puntos al enviar nuestra solución 😀

**Referencias**

Ibarra Romero Gabriel, 2017, Resolviendo Problemas con Inteligencia y elegancia, _https://www.amazon.com.mx/Resolviendo-problemas-inteligencia-y-elegancia-ebook/dp/B08D9V3JVG_