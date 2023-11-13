#include <bits/stdc++.h>
using namespace std;
 
// Acacius and String

string target = "abacaba";
bool checkOnce(string s) {
    int out = 0;
    for (int i = 0; i < s.length(); i++) {
        bool flag = true;
        // Check current index for occurrence of target
        for (int j = 0; j < target.length(); j++) {
            if (s[i + j] != target[j]) {
                flag = false;
                break;
            }
        }
        // If the target string was found, increase counter
        out += flag;
    }

    return out == 1;
}

void solve(int n, string s) {
    // Intuition: Brute force check every index in s.
    
    string out;
    // Loop through each index
    for (int i = 0; i < n; i++) {
        bool flag = true;
        // Check current index for occurrence of target
        for (int j = 0; j < target.length(); j++) {
            if (s[i + j] != target[j] && s[i + j] != '?') {
                flag = false;
                break;
            }
        }
        // If the target string was found, check that it only exists once
        if (flag) {
            string temp = s;
            temp.replace(i, target.length(), target);
            
            if (checkOnce(temp)) {
                out = temp;
                break;
            }
        }
    }

    if (out.length() == 0) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (char val : out) {
        val == '?' ? cout << 'x' : cout << val;
    }
    cout << '\n';
}
 
int main() {
    int t;
    int n;
    string s;
 
    cin >> t;
    while (t--) {
        cin >> n >> s;
        solve(n, s);
    }
 
    return 0;
}
