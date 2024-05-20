#include <bits/stdc++.h>
using namespace std;

// Songs Compression

void solve(long long int n, long long int m, long long int currSum, vector<long long int> arr) {
    // Intuition: Find space saved for each compression, sort in descending order.
    long long int out = 0;
    long long int i = 0;
    
    sort(arr.begin(), arr.end(), greater<long long int>());

    while (currSum > m && i < n) {
        currSum -= arr[i];
        i++;
        out++;
    }

    if (currSum > m) {
        out = -1;
    }
    
    cout << out << '\n';
}

int main() {
    long long int n;
    long long int m;
    long long int a;
    long long int b;
    long long int currSum = 0;
    vector<long long int> arr;
 
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = a - b;
        currSum += a;
    }
    solve(n, m, currSum, arr);
 
    return 0;
}
