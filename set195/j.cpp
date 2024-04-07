#include <bits/stdc++.h>
using namespace std;

// Higher Order Functions

string s;
int l = 0;

int eval() {
    int out = 0;
    int curr;

    while (true) {
        // Skip first character since it will always be '('
        l++;

        // Check for unit type "()"
        if (s[l] == ')') {
            curr = 0;
            l++;
        }
        else {
            curr = eval();
            // Skip last character of function since it will always be ')'
            if (s[l] == ')') {
                l++;
            }
        }

        if (l >= s.size() || s[l] == ')') {
            // Terminate current function
            out = max(out, curr);
            break;
        }

        // Check for "->"
        if (s[l] == '-' && s[l + 1] == '>') {
            l += 2;
            out = max(out, curr + 1);
        }
    }

    return out;
}

void solve() {
    // Intuition: Implement recursive evaluation.
    cout << eval() << '\n';
}

int main() {
    cin >> s;
    solve();
 
    return 0;
}
