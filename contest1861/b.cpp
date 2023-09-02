#include <bits/stdc++.h>
using namespace std;

// Two Binary Strings

int main() {
    int t;
    string a;
    string b;
    bool flag;

    cin >> t;
    while (t--) {
        cin >> a;
        cin >> b;
        flag = false;
        
        // Intuition: Print YES if '01' is present at the same index in both strings,
        //            otherwise print NO.
        for (int i = 0; i < a.length() - 1; i++) {
            if (a[i] == '0' && b[i] == '0' && a[i + 1] == '1' && b[i + 1] == '1') {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
