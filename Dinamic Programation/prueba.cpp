#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int closest_sum(int arr[], int n, int target) {
    int closest = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        int total = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                total += arr[j];
            }
        }
        if (abs(target - total) < abs(target - closest)) {
            closest = total;
        }
    }
    return closest;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int closest = closest_sum(arr, n, target);
    cout << closest << endl;
    return 0;
}
