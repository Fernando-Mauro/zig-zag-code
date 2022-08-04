// https://omegaup.com/arena/problem/La-Tiendita-de-don-Alberto//
#include <bits/stdc++.h>

using namespace std;

int main()
{
   //se declaran las variables
    int n, p, k;
    //ocupamos un map para poder buscar mas rapido y sin tantos algoritmos los productos 
    map<int, int> productos;
    int numero = 5;
    //este while se cumplira siempre y cuando la variable numero sea mayor que 1
   //ya que un numero mayor que 1 se considera true :)
    while (numero--)
    {
      //cantidad de productos de ese dia
        cin >> n;
        while (n--)
        {
            // se pide el producto y la cantidad
            cin >> p >> k;
            //se comprueba que exista dentro del mapa 
            if (productos.find(p) != productos.end())
            {
                productos[p] += k;
            }
            else
            {
               // si no hay se agrega un producto a el map con la llave de el producto y su cantidad
                productos[p] = k;
            }
        }
    }
    //un iterador para poder recorrer el mapa e imprimir los elementos resultantes
    for (auto it : productos)
    {
        int p = it.first;
        int k = it.second;
        cout << p << " " << k << endl;
    }
    return 0;
}