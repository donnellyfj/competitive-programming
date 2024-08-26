#include <bits/stdc++.h>
using namespace std;

// Power Walking

void solve(int n, vector<int> arr) {
    // Intuition: Output number of unique items until there are more children than items,
    //            then add 1 each time
    int unique = set<int>(arr.begin(), arr.end()).size();
    int out = unique;

    for (int i = 1; i <= n; i++) {
        if (i > unique) {
            out++;
        }
        cout << out << ' ';
    }
    
    cout << '\n';
}
 
int main() {
    int t;
    int n;
    vector<int> arr;

    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }

    return 0;
}
