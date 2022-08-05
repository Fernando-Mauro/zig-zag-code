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
En este ejemplo podemos ver que nos dan una matiz de 5 filas por 3 columnas. En la salida estan las posiciones de todas las minas en la matriz. <br>
> Notese que la esquina superior izquierda de la matriz es __1,1__.