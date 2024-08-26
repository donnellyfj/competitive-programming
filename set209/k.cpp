#include <bits/stdc++.h>
using namespace std;

// Lost Tree

void solve(int n) {
    // Intuition: Query nodes on smaller side of bipartite graph
    unordered_map<int, set<int>> adj;

    // Initial query with node 1
    cout << "? 1\n";
    int temp;
    vector<int> odds;
    vector<int> evens;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (i == 0) {
            // Skip first node with distance 0
            continue;
        }
        if (temp % 2) {
            if (temp == 1) {
                // Add node adjacent to node 1 to adj
                adj[1].insert(i + 1);
            }
            odds.push_back(i + 1);
        }
        else {
            evens.push_back(i + 1);
        }
    }
    
    // Query the smaller of the two sets (even or odd)
    vector<int> queries;
    if (odds.size() <= evens.size()) {
        queries = odds;
    }
    else {
        queries = evens;
    }

    for (int i = 0; i < queries.size(); i++) {
        // Make query
        cout << "? " << queries[i] << '\n';
        // Read result and store when distance is 1 if not already in adj
        int res;
        int neighbor;
        for (int j = 0; j < n; j++) {
            cin >> res;
            int curr = queries[i];
            neighbor = j + 1;
            if (res == 1) {
                // Keep order consistent so we dont have both (a, b) and (b, a) in adj
                if (neighbor < curr) {
                    swap(neighbor, curr);
                }
                // Add (curr, res) to set if it doesn't already exist
                if (adj[curr].find(neighbor) == adj[curr].end()) {
                    adj[curr].insert(neighbor);
                }
            }
        }
    }

    // Output pairs
    cout << "!\n";
    for (auto currPair : adj) {
        for (int neighbor : currPair.second) {
            cout << currPair.first << ' ' << neighbor << '\n';
        }
    }
}

int main() {
    int n;

    cin >> n;
    solve(n);

    return 0;
}
