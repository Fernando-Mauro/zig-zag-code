#include <bits/stdc++.h>

using namespace std;

stack <int> elements;
stack <int> maxElements;


void add (){
    int a;
    cin >> a;
    
    elements.push(a);
    
    int maxElementActual = (maxElements.empty()) ? 0 : maxElements.top();
    
    maxElementActual = max(maxElementActual, a);
    maxElements.push(maxElementActual);
}

void erase(){
    elements.pop();
    maxElements.pop();   
}

void maxElement(){
    cout << maxElements.top() << "\n";

}

int main() {
    int q;

    cin >> q;

    while(q--){
        int instruction;
        cin >> instruction;

        switch(instruction){
            case 1: add(); break;
            case 2: erase(); break;
            case 3: maxElement(); break;
        }
    }
    return 0;
}