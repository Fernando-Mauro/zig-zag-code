// https://omegaup.com/arena/problem/OMI-2019-Spider-Man#problems
#include <bits/stdc++.h>

using namespace std;


long long int pisos, ventanas, energia, costoH, costoV;

long long int solve(){
    long long int visitados = 0;

    if(costoH < costoV){
        long long int costoPorFilaTotal = (costoH * (ventanas - 1)) + costoV;        
        long long int filasTotalesVisitadas = energia / costoPorFilaTotal;

        visitados += (filasTotalesVisitadas) * ventanas;
        energia -= ((filasTotalesVisitadas) * ventanas) * costoH;

        long long int ventanasIndividuales = (energia / costoH);

        if(filasTotalesVisitadas == 0){
            ventanasIndividuales ++;
        }
        visitados += ventanasIndividuales;

    }else{
        long long int costoPorColumnaTotal = (costoV * (pisos - 1)) + costoH;        
        long long int columnasTotalesVisitadas = energia / costoPorColumnaTotal;

        visitados += (columnasTotalesVisitadas) * pisos;
        energia -= ((columnasTotalesVisitadas) * pisos) * costoV;

        long long int pisosIndividuales = (energia / costoV) ;
        if(columnasTotalesVisitadas == 0){
            pisosIndividuales ++;
        }

        visitados += pisosIndividuales;

    }    

    return visitados;
}

int main(){
    cin >> pisos >> ventanas >> energia >> costoH >> costoV;

    cout << solve();
    return 0;
}