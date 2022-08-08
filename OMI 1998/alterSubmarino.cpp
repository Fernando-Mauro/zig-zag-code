#include <iostream>
using namespace std;
char submarino[101][101];
char visitados[101];
unsigned char cola[100];
int main()
{
   int N, E, T;
   int a, b;
   int t, h, nodo;
   int head, tail;
   int total;
   // Lee la entrada
   cin >> N >> E >> T;
   for (int i = 0; i < E; i++)
   {
      cin >> a >> b;
      submarino[a][b] = 'X';
      // Marca los enlaces entre los nodos
      submarino[b][a] = 'X';
   }
   // Inicializa las variables
   total = 0;
   t = 0;
   head = tail = 0;
   cola[head++] = N;
   // mete el primero nodo en la cola
   visitados[N] = 'X';
   // (N es el nodo de la // salida de emergencia)
   while (tail != head && t < T - 1)
   {
      t++;
      // Incrementa la unidad de tiempo
      h = head;
      // Saca todos los que estén en la cola
      // en ese momento (pero
      // sin afectar los que apenas va a meter)
      while (tail != h)
      {
         nodo = cola[tail++];
         // Siguiente elemento
         // Mete todos los que están conectados con "nodo"
         for (int i = 1; i <= N; i++)
         {
            // Si están conectados y aún no
            // se ha tomado en cuenta,
            // lo mete en la cola y lo marca como procesado
            if (submarino[nodo][i] == 'X' && visitados[i] != 'X')
            {
               visitados[i] = 'X';
               // lo marca como visitado
               cola[head++] = i;
               // lo mete a la cola
               total++;
            }
         }
      }
   }
   // Respuesta
   cout << total;
   return 0;
}