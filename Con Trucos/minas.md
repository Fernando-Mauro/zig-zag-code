## **Minas**
### [Link al problema](https://omegaup.com/arena/problem/minas) <br>
Este problema es muy interesante, a simple vista es muy sencillo, el objetivo es el siguiente: <br>
Dado _n_ * _m_ caracteres (o una matriz de _n_ * _m_) debemos indicar en donde se encuentran minas, una mina esta representada por un __*__ y una porcion de tierra esta representada por un __+__. <br>
Veamos el siguiente ejemplo: 
<table style="width:100%; text-align:center;">
   <tr>
      <td style="width:50%">Entrada</td>
      <td style="width:50%">Salida</td>
   </tr>
   <tr>
      <td style="width:50%">
         5 3 <br>
         +++ <br>
         *+* <br>
         ++* <br>
         *** <br>
         +** <br>
      </td>
      <td style="width:50%">
         2 1 <br>
         2 3 <br>   
         3 3 <br> 
         4 1 <br>
         4 2 <br>     
         4 3 <br>     
         5 2 <br>     
         5 3 <br>     
      </td>
   </tr>
</table>

En este ejemplo podemos ver que nos dan una matiz de 5 filas por 3 columnas. En la salida estan las posiciones de todas las minas en la matriz.
</br>
> Nótese que la esquina superior izquierda de la matriz es __1,1__ <br>

Al analizar por un momento el problema nos damos cuenta de que se puede resolver facilmente con un bucle for anidado, el superior controlara a `i` y el interno controlara a `j`: <br>

```cpp
   #include <bits/stdc++.h>

   using namespace std;

   int main(){
      int n,m;
      cin >> n >> m;
      char aux;
      for(int i = 0; i < n; ++i){
         for(int j = 0; j < m; ++j){
            cin >> aux;
            if(aux == '*'){
               cout << i + 1 << " " << j + 1 << endl;
            }
         }
      }
   }
```

De esta manera podriamos pensar que el problema queda resuelto, pero veamos que sucede al enviar este codigo:
 
![imagen](https://drive.google.com/uc?export=view&id=1Pyq57vn2G4J_ZHw3xe0aPl9oOjLIkVAf)

Podemos observar que solo nos da 92 puntos, veamos porque pasa esto:
Utilizar `cin` y `cout` toma cierto tiempo, si vemos los limites del problema podemos ver que el valor maximo de `n` y `m` puede ser hasta 1,000, en el peor de los casos tendriamos que leer 1 millon de caracteres e imprimir otro millon mas, esto toma suficiente tiempo como para que no entre en tiempo.
<br>

Veamos algunas cosas que podrian ayudarnos a optimizar nuestro codigo: <br>
- Utilizar dos lineas de codigo que hagan mas rapida la entrada y salida mas rapidas, estas lineas lo que hacen es que desincronizan cin y printf para ser mas rapido, al agregar estas lineas solo podemos utilizar cin y cout: <br>
```cpp
std::cin.tie(nullptr);
std::ios_base::sync_with_stdio(false);
```

Probemos ahora enviando este codigo:
```cpp
#include <bits/stdc++.h>

using namespace std;

int main(){
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   char auxiliar;
   for(int i = 0; i < n; ++i){ 
      for(int j = 0; j < m; ++j){ 
         cin >> auxiliar;
         if(auxiliar == '*'){
            cout << i + 1 << " " << j + 1 << endl;
         }
      }
   }
   return 0;
}

```

![imagen](https://drive.google.com/uc?export=view&id=13SCdWobPlPqkct_R2as0GaCsEHkLW-Lz)

Comov vemos el tiempo ha bajado considerablemente pero no lo suficiente, cin y cout con la optimizacion anterior se vuelven mas rapidos, pero jamas al nivel de `printf` y `scanf`, asi que utilizemoslos: <br>
```cpp
#include <cstdio>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char aux;
    for(int i = 0; i< n; ++i){
        for(int j = 0; j < m ; ++j){
            scanf(" %c", &aux); 
            if(aux == '*'){
               printf("%d ",i + 1);
               printf("%d\n", j + 1);
            }
        }
    }
    return 0;
}
```
Con este cambio nos dara 100 puntos el problema 😃