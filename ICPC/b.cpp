#include <bits/stdc++.h>
using namespace std;
 
// Starving
 
void solve(int n, long long int h, vector<long long int> arr) {
    // Intuition: Wait as long as you can before eating a watermelon.
    long long int time = 0;
    int i = 0;

    while (i < n + 1) {
        if (h > n + 1 - i) {
            cout << "YES\n";
            return;
        }
        if (i == n) {
            if (h > 0) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
            return;
        }
        // Wait before moving
        if (i > 0 and arr[i + 1] > 0 && h > 2) {
            long long int steps = (h - 1) / 2;
            time += 2 * steps;
            h -= 2 * steps;
        }
        // Move and eat watermelon
        i++;
        if (arr[i] > 0) {
            h += arr[i] + time;
        }
        h--;
        if (h <= 0) {
            cout << "NO\n";
            return;
        }
        time++;
    }
}
 
int main() {
    int n;
    long long int h;
    vector<long long int> arr;

    cin >> n >> h;
    arr.resize(n + 1);
    arr[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> arr[i];
    }
    solve(n, h, arr);
 
    return 0;
}
