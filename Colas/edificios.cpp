#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long int i64;

i64 maxAreaHistogram(const vector<i64>& heights) {
    i64 maxArea = 0;
    i64 n = heights.size();
    stack<i64> st; 

    i64 i = 0;
    while (i < n) {
        if (st.empty() || heights[st.top()] <= heights[i]) {
            st.push(i);
            i++;
        } else {
            i64 top = st.top();
            st.pop();
            i64 height = heights[top];
            i64 width = st.empty() ? i : i - st.top() - 1;
            i64 area = height * width;
            maxArea = max(maxArea, area);
        }
    }
    while (!st.empty()) {
        i64 top = st.top();
        st.pop();
        i64 height = heights[top];
        i64 width = st.empty() ? i : i - st.top() - 1;
        i64 area = height * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<i64> histogram(n);
    for(int i = 0; i < n; ++i){
        cin >> histogram[i];
    }

    cout << maxAreaHistogram(histogram);
    return 0;
}
