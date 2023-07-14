// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=1012
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int velocity, time;
    while(scanf("%d%d", &velocity,&time) != EOF){
        printf("%d\n", 2 * velocity * time);
    }
    return 0;
}