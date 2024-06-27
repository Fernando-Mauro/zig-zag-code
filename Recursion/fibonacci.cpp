#include <bits/stdc++.h>

using namespace std;

int memo[10000];

int fib(int n){
	if (n <= 1)
		return n;

	if (memo[n] != 0)
		return memo[n];
    
	else {
		memo[n] = fib(n - 1) + fib(n - 2);
		return memo[n];
	}
}

// Driver Code
int main()
{
	int n = 6;
	cout << fib(n);
	return 0;
}
