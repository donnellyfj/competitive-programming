#include <bits/stdc++.h>
using namespace std;
 
// Long Comparison
 
void solve(int x1, int p1, int x2, int p2) {
    // Intuition: Remove trailing zeroes, then compare remaining numbers.
    // Remove redundant trailing zeroes
    int minZeroes = min(p1, p2);
    p1 -= minZeroes;
    p2 -= minZeroes;

    // Find lengths of each number
    int len1 = 0;
    int temp = x1;
    while (temp) {
        len1 += 1;
        temp /= 10;
    }

    int len2 = 0;
    temp = x2;
    while (temp) {
        len2 += 1;
        temp /= 10;
    }

    // Compare numbers
    if (len1 + p1 > len2 + p2) {
        cout << ">\n";
    }
    else if (len1 + p1 < len2 + p2) {
        cout << "<\n";
    }
    // Numbers have same number of digits, meaning numbers fit within int bounds
    // since trailing zeroes were removed
    else {
        while (p1--) {
            x1 *= 10;
        }
        while (p2--) {
            x2 *= 10;
        }
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
}
 
int main() {
    int t;
    int n;
    int x1;
    int p1;
    int x2;
    int p2;
 
    cin >> t;
    while (t--) {
        cin >> x1 >> p1;
        cin >> x2 >> p2;
        solve(x1, p1, x2, p2);
    }
 
    return 0;
}
