// incluimos la librearia bits porque somos chidos
#include   <bits/stdc++.h>

using namespace std;

int main(){
   //declaramos el string para guardar la cadena
    string palabras;
    //con getline podemos obtener una cadena y almacenarlas con espacios, hasta que haya un salto de linea
    getline(cin, palabras);
    //declaramos contador de los instructores
    int contador = 0;
    // un for que llegue hasta el ultimo indice de la cadena
    // el atributo size( ) devuelve el tamaño de la cadena
    for(int i = 0; i < palabras.size(); ++i){
      // si la el caracter en el que estamos es igual a un espacio aumentamos uno a el contador
        if(palabras[i] == ' '){
            contador++;
        }
    }
    //mostramos el contador mas uno, porque el ultimo instructor no lo cuenta :D
    cout << contador + 1 << endl;
    return 0;
}