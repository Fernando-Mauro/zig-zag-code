// https://omegaup.com/arena/problem/Encuesta-Reloaded
#include <bits/stdc++.h>

using namespace std;

struct persona{
   float id;
   string nombre;
   float peso;
   float estatura, IMC;
};
bool ordenar(persona &first_node, persona &second_node){
   if(first_node.IMC > second_node.IMC){
      return true;
   }else{
      return false;
   }
}
int main(){
   int n;
   cin >> n;
   vector <persona> personas(n);
   for(int i = 0; i < n; i++){
      string name;
      float peso, id;
      float estatura;
      cin >> id;
      cin.ignore();
      getline(cin, name);
      cin >> peso;
      cin >> estatura;
      personas[i].id = id;
      personas[i].nombre = name;
      personas[i].peso = peso;
      personas[i].estatura = estatura;
      personas[i].IMC = personas[i].peso / (pow(personas[i].estatura,2));
   }
   sort(personas.begin(), personas.end(), ordenar);
   for(int i = 0; i < n; i++){
      cout <<  fixed << setprecision(0) << personas[i].id << " " << personas[i].nombre  << " "; 
      cout << fixed << setprecision(1) << personas[i].IMC << endl;
   }
   return 0;
}