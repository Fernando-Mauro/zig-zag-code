// https://omegaup.com/arena/problem/Minas/
// 100% 😎
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char auxiliar;
    for(int i = 0; i < n; ++i){ 
        for(int j = 0; j < m; ++j){ 
            scanf(" %c", &auxiliar);
            if(auxiliar == '*'){
                printf("%d", i + 1);
                printf(" %d\n", j + 1);
            }
        }
    }
    return 0;
}