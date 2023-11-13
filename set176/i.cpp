#include <bits/stdc++.h>
using namespace std;
 
// Secret Santa

void solve(int n, vector<int> arr) {
    // Intuition: Start with unique values and then form cycles.
    unordered_map<int, vector<int>> inMap;
    for (int i = 0; i < n; i++) {
        arr[i]--;
        inMap[arr[i]].push_back(i);
    }

    // Count number of unqique values. This is our first output
    vector<int> seen(n, 0);
    int numUnique = 0;
    for (int i = 0; i < n; i++) {
        if (seen[arr[i]] == 0) {
            numUnique++;
            seen[arr[i]]++;
        }
    }
    cout << numUnique << '\n';

    // Find nodes with no in edges and multiple in edges
    vector<int> noIn;
    vector<int> multIn;
    for (int i = 0; i < n; i++) {
        if (inMap.find(i) == inMap.end()) {
            noIn.push_back(i);
        }
        else if (inMap[i].size() > 1) {
            multIn.push_back(i);
        }
    }
    int numNodes = noIn.size();

    if (numNodes > 0) {
        for (int nodeIdx = 0; nodeIdx < numNodes; nodeIdx++){
            // Find a node with multiple input edges
            int i = multIn.back();
            if (inMap[i].size() > 1) {
                // Make sure not to use input edge from the lone node
                int edgeIdx = inMap[i].size() - 1;
                if (inMap[i][edgeIdx] == noIn[nodeIdx]) {
                    swap(inMap[i][edgeIdx], inMap[i][edgeIdx - 1]);
                }
                // Redirect the extra edge to point to the lone node
                arr[inMap[i][edgeIdx]] = noIn[nodeIdx];
                inMap[i].pop_back();
                if (inMap[i].size() == 1) {
                    multIn.pop_back();
                }
            }
        }
    }

    // Display the resulting array
    for (int i = 0; i < n; i++) {
        cout << arr[i] + 1 << ' ';
    }
    cout << '\n';
}
 
int main() {
    int t;
    int n;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }
 
    return 0;
}
