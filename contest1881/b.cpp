#include <bits/stdc++.h>
using namespace std;
 
// Three Threadlets
 
void solve(vector<int> arr) {
    // Intuition: Try to cut to length of smallest string
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 3; i++) {
        if (arr.front() == arr.back()) {
            break;
        }
        int curr = arr.back();
        arr.back() = arr.front();
        arr.push_back(curr - arr.front());
        sort(arr.begin(), arr.end());
    }
    if (arr.front() == arr.back()) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main() {
    int t;
    vector<int> arr(3);
 
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) {
            cin >> arr[i];
        }
        solve(arr);
    }
 
    return 0;
}
