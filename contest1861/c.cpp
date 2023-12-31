#include <bits/stdc++.h>
using namespace std;

// Queries for the Array

int main() {
    int t;
    int minUnsort;
    int maxSort;
    int idx = 0;
    bool flag;
    char curr;
    string s;

    cin >> t;
    while (t--) {
        s.clear();
        cin >> s;
        maxSort = 0;
        minUnsort = 0;
        idx = 0;
        flag = true;
        
        // Intuition: Keep track of longset sorted prefix and shortest unsorted prefix.
        //            If length(longest sorted) >= length(shortest unsorted), print NO, else YES.
        //            Also print NO if an array of length 1 or 0 is unsorted.
        for (int i = 0; i < s.length(); i++) {
            curr = s[i];
            if (s[i] == '+') {
                idx++;
            }
            else if (s[i] == '-') {
                if (idx == maxSort) {
                    maxSort--;
                }
                if (idx == minUnsort) {
                    minUnsort = 0;
                }
                idx--;
            }
            else if (s[i] == '1') {
                maxSort = idx;
            }
            else if (s[i] == '0') {
                if (idx < 2) {
                    cout << "NO\n";
                    flag = false;
                    break;
                }
                if (minUnsort == 0) {
                    minUnsort = idx;
                }
                else {
                    minUnsort = min(minUnsort, idx);
                }
            }
            if (maxSort >= minUnsort && maxSort > 0 && minUnsort > 0) {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        }
    }

    return 0;
}
