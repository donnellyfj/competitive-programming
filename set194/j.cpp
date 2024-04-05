#include <bits/stdc++.h>
using namespace std;

// Omkar and Determination

void solve(int n, int m, vector<vector<char>> arr, int q, vector<vector<int>> qArr) {
    // Intuition: Look for a case where arr[i][j] and arr[i+1][j-1] are both blocked, compute prefix sum.
    vector<int> seen(m, 0);
    int total = 0;

    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][j] == 'X' and arr[i + 1][j - 1] == 'X') {
                total += 1;
            }
        }
        seen[j] = total;
    }

    for (int i = 0; i < q; i++) {
        int l = qArr[i][0];
        int r = qArr[i][1];
        if (seen[r] - seen[l] > 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}

int main() {
    int n;
    int m;
    int q;
    vector<vector<char>> arr;
    vector<vector<int>> qArr;

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> q;
    qArr.resize(q);
    for (int i = 0; i < q; i++) {
        qArr[i].resize(2);
        cin >> qArr[i][0];
        qArr[i][0]--;
        cin >> qArr[i][1];
        qArr[i][1]--;
    }
    solve(n, m, arr, q, qArr);
 
    return 0;
}
