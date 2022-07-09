// https://omegaup.com/arena/problem/COMI-Parentesis
#include <bits/stdc++.h>

using namespace std;

bool esValida (string s) {
  stack<char> pila;

  for (int i=0; i<s.size(); i++) {
    char actual = s[i];
    if (actual == '(' ||  actual == '{'  || actual == '[' ) {
      pila.push(actual);
    } else {
      if (pila.empty()) {
        return false;
      } else if( actual == ')') {
        if( pila.top() != '('){
          return false;
        }else {
          pila.pop();
        }
      }
    }
  }
  
  if (pila.empty()) {
    return true;
  }

  return false;
}

int main() {

  string expresion;
  cin >> expresion;

    if (esValida(expresion)) {
      cout<<"SI"<<endl;
    } else {
      cout<<"NO"<<endl;
    }

  return 0;
}