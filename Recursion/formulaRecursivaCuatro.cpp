// https://omegaup.com/arena/problem/Formula-Recursiva-Cuatro/
// Esta recursion tiene que ser con memorizacion, asi que si quieres tener 66 puntos puedes aplicar la version ineficiente:
/*
#include <iostream>

using namespace std;
int numero;

int funcion(int n){
	if(n <= 3){
		return 1;
	}
	return funcion(n - 1 ) + funcion( n- 2) + funcion (n -  3);
}
int main(){
	cin >> numero;
	cout << funcion(numero);
} */
#include <bits/stdc++.h>
vector <int> memoria(40);
int funcion(int n){
	if( n >= 4){
		if(memoria[n] != -1){
			
		}
	}
}
using namespace std;

int main(){

   return 0;
}