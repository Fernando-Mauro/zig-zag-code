#include <bits/stdc++.h>

using namespace std;
int contador = 0;
int buscare(string buscar, stack <string> &coches,int n){
	for(int i = 0; i < n; i++){
		if(coches.empty()){
			return 0;
		}
		if(buscar == coches.top()){
			return 0;
		}else{
			coches.pop();
			contador++;
		}
	}
}
int main(){
	int n;
	cin >> n;
	stack <string> coches;
	for(int i = 0; i < n; i++){
		string placa;
		cin >> placa;
		coches.push(placa);
	}
	string buscar;
	cin >> buscar;
	buscare(buscar, coches,n);
	if(!coches.empty()){
		cout << contador + 1 << endl;
	}else{
		cout << "No existe el auto" << endl;
	}
	return 0;
}