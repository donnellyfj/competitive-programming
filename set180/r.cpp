#include <bits/stdc++.h>
using namespace std;
 
// What Is It?

void solve(int n) {
    // Intuition: Flip the problem. Start with identity permutaion, and make the most expensive move each time.
    vector<int> p(n);
    // Initialize p as identity permutation
    iota(p.begin(), p.end(), 1);
    long long int cost = 0;
    vector<vector<int>> moves;

    // Variable to keep track of the offset from the ends of the array
    int j = 1;
    for (int i = 0; i < n - 1; i++) {
        // Move the j-th index from the right and left of p to the farthest point
        if (i % 2 == 0) {
            swap(p[j - 1], p[n - 1]);
            moves.push_back({j, n});
            cost += pow(n - j, 2);
        }
        else {
            swap(p[0], p[n - j - 1]);
            moves.push_back({n - j, 1});
            cost += pow(n - j - 1, 2);
            j++;
        }
    }

    // Outputs
    cout << cost << '\n';
    
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << '\n';

    cout << n - 1 << '\n';

    for (int i = n - 2; i >= 0; i--) {
        cout << moves[i][0] << ' ' << moves[i][1] << '\n';
    }
}
 
int main() {
    int t;
    int n;
 
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
 
    return 0;
}