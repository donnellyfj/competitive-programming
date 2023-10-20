#include <bits/stdc++.h>
using namespace std;
 
// Cards in a Row
 
void solve(string s) {
    // Intuition: Add powers of 2.
    long long int power = 1;
    long long int out = 0;
    long long int mod = 1000000007;

    while (s.size() > 0) {
        if (s.back() == 'O') {
            out += power;
            out %= mod;
        }

        power = (power * 2) % mod;
        s.pop_back();
    }

    cout << out << '\n';
}
 
int main() {
    string s;

    cin >> s;
    solve(s);
 
    return 0;
}
