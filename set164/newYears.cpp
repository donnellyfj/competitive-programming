#include <bits/stdc++.h>
using namespace std;

// New Year Concert

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int ans = 0;
    int covered = -1;
    vector<vector<int>> s;
    for (int i = 0; i < n; i++) {
        // Update GCDs to include next value
        for (auto& t : s) {
            t[2] = gcd(t[2], a[i]);
        }
        s.push_back({i, i, a[i]});

        // Merge
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            if (cnt > 0 && s[j][2] == s[cnt - 1][2]) {
                s[cnt - 1][1] = s[j][1];
            } else {
                s[cnt++] = s[j];
            }
        }
        s.resize(cnt);

        // Determine output
        for (auto& t : s) {
            // Find start of segment with length of current GCD (look for potential boring segments)
            int at = i - t[2] + 1;
            // If there is a problem segment within current window, make change
            if (t[0] <= at && at <= t[1]) {
                if (at > covered) {
                    ans += 1;
                    covered = i;
                }
            }
        }
        cout << ans << " \n"[i == n - 1];
    }
    return 0;
}
