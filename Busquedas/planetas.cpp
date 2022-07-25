//https://omegaup.com/arena/problem/Planetas/
#include <bits/stdc++.h>

using namespace std;

double balanceo(double posicion, vector <double> &planetas){
	double fuerzas = 0;
	for(int i = 0; i < planetas.size(); i++){
		fuerzas += 1/(planetas[i] - posicion);
	}
	return fuerzas;
}

double busqueda(double inicio, double final, vector <double> &planetas){
	int maximo = 25;
	// maximo ^ 2 = 10,000,000 = 1,000 * 10,000 = decimales * maximo
	double mitad;
	double balanceado = 0;
	for(int i = 0; i < maximo; i++){
		mitad = (inicio + final) / 2;
		balanceado = balanceo(mitad, planetas);
		// si el las fuerzas totales son 0 entonces llegamos a la solucion B)
		if(balanceado > 0){
			final = mitad;
		}else{
			inicio = mitad;
		}
	}
	return inicio;
}

int main(){
	cin.tie(nullptr);	
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <double> planetas(n);
	for(int i = 0; i < n; ++i){ 
		cin >> planetas[i];
	}
	sort(planetas.begin(), planetas.end());
	// las soluciones al problemas son exactamente n - 1
	cout << n - 1 << endl;
	for(int i = 1; i < n; i++){
		// encontrar punto medio donde la fuerza neta del meteorito sobre los planetas sea 0
		cout << fixed << setprecision(3) << busqueda(planetas[i - 1], planetas[i], planetas) << " ";
	}
	return 0;
}