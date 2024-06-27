#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int main() {
    vector<int> v = {1,2,4,4,4,6,7};
    
    int value = 7;
    
    auto lb = lower_bound(v.begin(), v.end(), value);
    auto ub = upper_bound(v.begin(), v.end(), value);
    
    if(lb != v.end()){
        cout << "Lower Bound: " << (lb - v.begin()) << std::endl;
    }
    if(ub != v.end()){
        cout << "Upper Bound: " << (ub - v.begin()) << std::endl;
    }
    
    return 0;
}
