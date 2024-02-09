#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int size;
    cin >> size;
    map <char, int> letters;
    while(size--){
        char temp;
        cin >> temp;
        letters[temp]++;
    }
    int ones = min(letters['o'], min(letters['n'], letters['e']));
    letters['o'] -= ones;
    letters['n'] -= ones;
    letters['e'] -= ones;
    int zeros = min(letters['z'], min(letters['e'], min(letters['r'], letters['o'])));
    while(ones--){
        cout << 1 << " ";
    }
    while(zeros--){
        cout << 0 << " ";
    }

    return 0;
}