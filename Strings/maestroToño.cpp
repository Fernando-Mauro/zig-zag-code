// https://omegaup.com/arena/problem/El-maestro-Tono-Palabras/#problems
#include <bits/stdc++.h>

using namespace std;
// Esta solucion puede llegar a caer en un ciclo si no se ejecuta de la manera correcta, si se compila y ejecuta normalmente desde la terminal, pero si la entrada de otro archivo se redirije a el ejecutable ya no se cicla :)
int main(){
  string palabra = "";
  int contador = 0;
  while(cin>>palabra) { // Lee las palabras hasta que ya no encuentra mas.
    contador++;
    cout<<"P"<<contador<<" "<<palabra<<endl;
  }
   return 0;
}