#include <bits/stdc++.h> 

using namespace std;
#define MAX 1000000

vector <int> primos;
set <int> primosSet;
void fillCriba(){
    bitset <MAX> criba;
    criba.set();

    for (int i = 2; i < MAX; ++i){
        if(criba[i]){
            for(int j = i; j < MAX; j += i){
                criba.reset(j);
            }
            primos.push_back(i);
            primosSet.insert(i);
        }
    }
}

int numberDividers(int n){
    int original = n;
    int number = 0;
    for(int i = 0; i < primos.size() && primos[i] < original; ++i){
        if(n % primos[i] == 0){
            number++;
            n /= primos[i];
            i--;
        }
    }
    return number;
}

int main(){
    int first, second;
    cin >> first >> second;
    fillCriba();

    int subprimos = 0;
    for(; first <= second; first++){
        int divisores = numberDividers(first);
        if(primosSet.find(divisores) != primosSet.end()){
            subprimos++;
        }
    }

    cout << subprimos << endl;
    return 0;
}