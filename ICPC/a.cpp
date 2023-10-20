#include <bits/stdc++.h>
using namespace std;
 
// Maximize Meal Quality
 
void solve(int n, int k, vector<int> arr) {
    // Intuition: Sum all the numbers and then add the k greatest numbers.
    long long int out = 0;

    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (i < k) {
            out += arr[i];
        }
        out += arr[i];
    }

    cout << out << '\n';
}
 
int main() {
    int n;
    int k;
    vector<int> arr;

    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, k, arr);
 
    return 0;
}
