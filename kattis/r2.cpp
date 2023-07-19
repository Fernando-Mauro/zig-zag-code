// https://open.kattis.com/problems/r2
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int s, r1;
    scanf("%d%d", &r1, &s);
    int r2 = (s * 2) - r1;
    printf("%d\n", r2);
    return 0;
}