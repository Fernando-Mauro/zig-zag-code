//https://omegaup.com/arena/problem/Ordenando-Digitos/#problems
#include <bits/stdc++.h>
using namespace std;

int printvector(vector<int> &digitos) {
    for ( int i = 0; i < digitos.size(); ++i ) {
        cout << digitos[i] << " ";
    }
    return 0;
}

int main() {

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int size;
    vector<int> digitos;
    
    cin >> size;

    for ( int i = 0; i < size; ++i ) {
        int n; cin >> n;
        digitos.push_back(n);
    }

    stable_sort(digitos.begin(), digitos.end());

    printvector(digitos);

    return 0;
}