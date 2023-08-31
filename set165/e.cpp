#include <bits/stdc++.h>
using namespace std;

// Penalty (1153C)

void solve(vector<char> p1, vector<char> p2) {
    int kicks1 = 0;
    int kicks2 = 0;
    int p1Score = 0;
    int p2Score = 0;
    int p1Left = 5;
    int p2Left = 5;

    // Try p1 ? -> 1, p2 ? -> 0
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            p2Left--;
            if (p2[i / 2] == '1') {
                p2Score++;
            }
        }
        else {
            p1Left--;
            if (p1[i / 2] == '1' || p1[i / 2] == '?') {
                p1Score++;
            }
        }
        kicks1++;
        if ((p1Score + p1Left < p2Score) || (p2Score + p2Left < p1Score)) {
            break;
        }
    }

    p1Score = 0;
    p2Score = 0;
    p1Left = 5;
    p2Left = 5;

    // Try p2 ? -> 1, p1 ? -> 0
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            p2Left--;
            if (p2[i / 2] == '1' || p2[i / 2] == '?') {
                p2Score++;
            }
        }
        else {
            p1Left--;
            if (p1[i / 2] == '1') {
                p1Score++;
            }
        }
        kicks2++;
        if ((p1Score + p1Left < p2Score) || (p2Score + p2Left < p1Score)) {
            break;
        }
    }
    
    cout << min(kicks1, kicks2) << '\n';
}

int main() {
    int t;
    vector<char> p1(5);
    vector<char> p2(5);

    // cout << "Input num of test cases: ";
    cin >> t;

    while (t--) {
        // cout << "Input array: ";
        for (int idx = 0; idx < 5; idx++) {
            cin >> p1[idx];
            cin >> p2[idx];
        }

        solve(p1, p2);
    }
}
