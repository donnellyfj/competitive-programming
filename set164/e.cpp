#include <bits/stdc++.h>
using namespace std;

// Equalize by Divide

void solve(int n, vector<int> arr) {
    int maxIdx;
    int minIdx;
    set<int> arrUnique;
    vector<vector<int>> operations;

    for (int i : arr) {
        arrUnique.insert(i);
    }

    if (arrUnique.size() == 1) {
        cout << 0 << '\n';
        return;
    }
    else if (count(arr.begin(), arr.end(), 1) > 0) {
        cout << -1 << '\n';
        return;
    }
    
    while (arrUnique.size() != 1) {
        maxIdx = distance(arr.begin(), max_element(arr.begin(), arr.end()));
        minIdx = distance(arr.begin(), min_element(arr.begin(), arr.end()));
        arr[maxIdx] = arr[maxIdx] / arr[minIdx] + (arr[maxIdx] % arr[minIdx] != 0);
        operations.push_back({maxIdx, minIdx});

        arrUnique.clear();
        for (int i : arr) {
            arrUnique.insert(i);
        }
    }

    cout << operations.size() << '\n';
    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i][0] + 1 << ' ' << operations[i][1] + 1 << '\n';
    }

    cout << '\n';
}

int main() {
    int t;
    int n;
    vector<int> arr;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size: ";
        scanf("%d", &n);
        arr.resize(n);
        // cout << "Input array: ";
        for (int idx = 0; idx < n; idx++) {
            scanf("%d", &arr[idx]);
        }

        solve(n, arr);
    }
}
