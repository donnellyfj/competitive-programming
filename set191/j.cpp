#include <bits/stdc++.h>
using namespace std;

// Fix the String

void solve(int n, vector<char> arr, vector<char> a) {
    // Intuition: Check patterns in the binary string a.
    int out = 0;
    int m = n - 3;
    int i = 0;
    while (i < m) {
        // Check if no criteria
        if (a[i] == '0') {
            i++;
            continue;
        }

        // Check for patterns that make an answer impossible
        // 11
        if (i < m - 1 && a[i] == '1' && a[i + 1] == '1') {
            cout << "-1\n";
            return;
        }
        // 1xx1
        if (i < m - 3 && a[i] == '1' && a[i + 3] == '1') {
            cout << "-1\n";
            return;
        }

        // Check for patterns to fix
        // If next 3 values of a are 101, arr must be in form ()()()
        if (i < m - 2 && a[i] == '1' && a[i + 2] == '1') {
            for (int j = i; j < i + 6; j++) {
                if (((j - i) % 2) && arr[j] != ')') {
                    arr[j] = ')';
                    out++;
                }
                else if (((j - i) % 2 == 0) && arr[j] != '(') {
                    arr[j] = '(';
                    out++;
                }
            }
            i += 4;
        }
        // Otherwise next three values of a are 100, can use minimum of ()() and (())
        else {
            int cost1 = (arr[i] != '(') + (arr[i + 1] != ')') + (arr[i + 2] != '(') + (arr[i + 3] != ')');
            int cost2 = (arr[i] != '(') + (arr[i + 1] != '(') + (arr[i + 2] != ')') + (arr[i + 3] != ')');
            out += min(cost1, cost2);
            i += 4;
        }
    }
    
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    vector<char> arr;
    vector<char> a;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        a.resize(n - 3);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 3; i++) {
            cin >> a[i];
        }
        solve(n, arr, a);
    }
 
    return 0;
}
