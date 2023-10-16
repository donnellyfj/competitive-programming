#include <bits/stdc++.h>
using namespace std;
 
// Decreasing String
 
void solve(long long int pos, string s) {
    // Intuition: Find what string the position belongs to, and then create that string and find the index.
    // Find what string pos belongs to
    int stringNum = 0;
    int len = s.size();
    while (pos > len) {
        pos -= len;
        len--;
        stringNum++;
    }

    // Remove one character each iteration to make the string lexicographically minimal
    // Remove the first character that is greater than the one coming after it
    // Keep stack to find string
    vector<char> stack;
    int i = 0;
    while (i < s.size()) {
        if (stringNum == 0 || stack.empty() || stack.back() <= s[i]) {
            stack.push_back(s[i]);
            i++;
        }
        else {
            stack.pop_back();
            stringNum--;
        }
    }
    // Remove last character if not enough characters have been removed yet
    while (stringNum-- > 0) {
        stack.pop_back();
    }
    cout << stack[pos - 1];
}
 
int main() {
    int t;
    long long int pos;
    string s;

    cin >> t;
    while (t--) {
        cin >> s >> pos;
        solve(pos, s);
    }
    cout << '\n';
 
    return 0;
}
