#include <bits/stdc++.h>
using namespace std;

// Construct the String

void solve(int n, int b) {
    // Intuition: Repeat the first b letters.
    int numLetters = 0;

    while (numLetters < n) {
        char c = 'a';
        int i = 0;
        while (numLetters < n && i < b) {
            cout << char(c + i);
            i++;
            numLetters++;
        }
    }
    
    cout << '\n';
}

int main() {
    int t;
    int n;
    int a;
    int b;
 
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        solve(n, b);
    }
 
    return 0;
}
