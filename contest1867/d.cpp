#include <bits/stdc++.h>
using namespace std;
 
// Cyclic Operations
 
void solve(int n, int k, vector<int> b) {
    // Intuition: Check that length of graph cycle = k
    vector<int> visited(n, 0);

    // Check if k = 1, b should be in the form [1, 2, 3, 4, ..., n]
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            if (b[i] != i + 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }

    vector<int> order(n);
    int visitCnt = 1;

    // Visit each node that hasn't been visited and traverse until you find a cycle
    for(int j = 0;j < n;++j)
    {
        if(!visited[j])
        {
            int currIdx = j;
            int currNum = 0;

            // Count length of cycle
            while(!visited[currIdx])
            {
                visited[currIdx] = visitCnt;
                order[currIdx] = currNum++;
                currIdx = b[currIdx]-1;
            }
            // Check that we're not looking at a previous cycle
            if(visited[currIdx] != visitCnt)
            {
                visitCnt++;
                continue;
            }
            // Check that length of cycle = k
            if(currNum-order[currIdx] != k)
            {
                cout << "NO\n";
                return;
            }
            visitCnt++;
        }
    }
    cout << "YES\n";
}
 
int main() {
    int t;
    int n;
    int k;
    vector<int> b;
 
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> k;
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        solve(n, k, b);
    }
 
    return 0;
}
