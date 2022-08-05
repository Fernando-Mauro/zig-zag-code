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
 
![Imagen del veredicto del envio](https://www.dropbox.com/s/9qrc2aq4moiew5l/Screenshot%20from%202022-08-05%2014-04-41.png?dl=0)