#include <bits/stdc++.h>
using namespace std;
 
// Don't Try to Count
 
void solve(int n, int m, string x, string s) {
    // Intuition: Append string and check with brute force
    int out = 0;
    while (x.size() <= 200) {
        if (x.find(s) != string::npos) {
            cout << out << '\n';
            return;
        }
        x += x;
        out++;
    }
    cout << -1 << '\n';
}
 
int main() {
    int t;
    int n;
    int m;
    string x;
    string s;
 
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> s;
        solve(n, m, x, s);
    }
 
    return 0;
}
