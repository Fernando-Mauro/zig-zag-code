// https://omegaup.com/arena/problem/Minas/
/* solucion que da 100 puntos B)" */
#include <cstdio>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    char aux;
    for(int i = 0; i< n; ++i){
        for(int j = 0; j < m ; ++j){
            scanf(" %c", &aux); 
            if(aux == '*'){
               printf("%d ",i + 1);
               printf("%d\n", j + 1);
            }
        }
    }
    return 0;
}