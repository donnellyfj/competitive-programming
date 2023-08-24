#include <bits/stdc++.h>
using namespace std;

// Equalize by Divide

void solve(int n, vector<int> arr) {
    vector<vector<int>> ops(0, vector<int> (2, 0));
    vector<int> newOp;
    set<int> temp;
    int minIdx;
    int maxIdx;
    int ceilDiv;

    // Check if all numbers are the same
    for (int val : arr) {
        temp.insert(val);
    }
    if (temp.size() == 1) {
        cout << 0 << '\n';
        return;
    }
    // Check if operation is impossible (arr contains the number 1)
    else if(find(arr.begin(), arr.end(), 1) != arr.end()) {
        cout << -1 << '\n';
        return;
    }
    // Perform operations
    else {
        while (temp.size() > 1) {
            minIdx = distance(arr.begin(), min_element(arr.begin(), arr.end()));
            maxIdx = distance(arr.begin(), max_element(arr.begin(), arr.end()));
            // Ceiling division
            arr[maxIdx] = arr[maxIdx] / arr[minIdx] + (arr[maxIdx] % arr[minIdx] != 0);
            ops.push_back(vector<int>{maxIdx, minIdx});
            temp.clear();
            for (int val : arr) {
                temp.insert(val);
            }
        }
    }

    // Output answer
    cout << ops.size() << '\n';
    for (auto op : ops) {
        cout << op[0] + 1 << ' ' << op[1] + 1 << '\n';
    }
}

int main() {
    int i;
    int n;
    vector<int> arr;

    // cout << "Input num of test cases: ";
    scanf("%d", &i);

    while (i--) {
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
