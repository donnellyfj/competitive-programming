#include <bits/stdc++.h>
using namespace std;
 
// Incinerate
 
void solve(int n, int k, vector<int> h, vector<int> p) {
    // Intuition: Keep minheap of attack and damage
    // Find how many turns it will take for Genos to win
    int maxHealth = *max_element(h.begin(), h.end());
    // Create minheap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    for (int i = 0; i < n; i++) {
        minheap.push(make_pair(p[i], h[i]));
    }
    // Loop until monsters or Genos wins
    long long int damage = 0;
    while (!minheap.empty() and k > 0) {
        // Attack monsters
        maxHealth -= k;
        damage += k;
        if (maxHealth <= 0) {
            cout << "YES\n";
            return;
        }

        while (!minheap.empty() && minheap.top().second - damage <= 0) {
            minheap.pop();
        }
        if (!minheap.empty()){
            pair curr = minheap.top();
            k -= curr.first;
        }
        // minheap.pop();
    }

    if (k > 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main() {
    int t;
    int n;
    int k;
    vector<int> h;
    vector<int> p;
 
    cin >> t;
    while (t--) {
        cin >> n >> k;
            h.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        p.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        solve(n, k, h, p);
    }
 
    return 0;
}
