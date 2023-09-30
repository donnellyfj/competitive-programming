#include <bits/stdc++.h>
using namespace std;
 
// Long Comparison
 
void solve(int x1, int p1, int x2, int p2) {
    // Intuition: Remove extra trailing zeros, and then vectorize the leftover numbers.
    // Remove reduntant zeros
    int minZeros = min(p1, p2);
    p1 -= minZeros;
    p2 -= minZeros;
    // Same # of zeros
    if (p1 == p2) {
        if (x1 > x2) {
            cout << ">\n";
        }
        else if (x1 < x2) {
            cout << "<\n";
        }
        else {
            cout << "=\n";
        }
    }
    else {
        // Vectorize each number
        deque<int> d1;
        deque<int> d2;
        int temp = x1;
        while (temp) {
            d1.push_front(temp % 10);
            temp /= 10;
        }
        temp = x2;
        while (temp) {
            d2.push_front(temp % 10);
            temp /= 10;
        }
        // Pad smaller vector with available zeros
        while (p1) {
            d1.push_back(0);
            p1--;
            if (d1.size() > d2.size()) {
                cout << ">\n";
                return;
            }
        }
        while (p2) {
            d2.push_back(0);
            p2--;
            if (d2.size() > d1.size()) {
                cout << "<\n";
                return;
            }
        }
        

        // Compare vectors
        int tieBreak = 0;
        while (!d1.empty() && !d2.empty()) {
            if (d1.back() > d2.back()) {
                tieBreak = 1;
            }
            else if (d1.back() < d2.back()) {
                tieBreak = 2;
            }
            d1.pop_back();
            d2.pop_back();
        }
        // Check if either vectors are empty
        if (!d1.empty()) {
            cout << ">\n";
        }
        else if (!d2.empty()) {
            cout << "<\n";
        }
        else {
            if (tieBreak == 1) {
                cout << ">\n";
            }
            else if (tieBreak == 2) {
                cout << "<\n";
            }
            else {
                cout << "=\n";
            }
        }
    }
}
 
int main() {
    int t;
    int x1;
    int p1;
    int x2;
    int p2;

 
    cin >> t;
    while (t--) {
        cin >> x1 >> p1 >> x2 >> p2;
        solve(x1, p1, x2, p2);
    }
 
    return 0;
}
