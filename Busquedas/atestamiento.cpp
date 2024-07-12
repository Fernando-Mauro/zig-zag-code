#include <bits/stdc++.h> 

using namespace std;

struct Car{
    string placa;
    int pos;
    // por edad
    // Sobrecarga de operador
    bool operator<(Car a){
        for(int i = 0; i < a.placa.size(); ++i){
            if(a.placa[i] > this->placa[i])
                return true;
            else
                return false; 
        }
        // return this->placa < a.placa;
    }

};

bool isLess(string a, string b){
    if(a.size > b.size())
    // 00000012 13

    for(int i = 0; i < a.placa.size(); ++i){
            if(a.placa[i] > this->placa[i])
                return true;
            else
                return false; 
    }
}
int solve(vector <Car> &cars, string placa){
    // Ordenar los autos
    sort(cars.begin(), cars.end());

    int start = 0;
    int end = cars.size() - 1;
    int middle;

    while(start < end){
        middle = (start + end) / 2;
        if(cars[middle].placa == placa){
            return cars[middle].pos;
        }else if(cars[middle].placa < placa){
            start = middle + 1;
        }else{
            end = middle - 1;
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);   

    int n;
    cin >> n;

    
    vector <Car> cars(n);

    for(int i = 0; i < n; ++i){
        cin >> cars[i].placa;
        cars[i].pos = i + 1;
    }

    string placa;
    cin >> placa;

    int pos = solve(cars, placa);
    cout << (cars.size() -  solve(cars, placa)) + 1 << "\n";
    return 0;
}