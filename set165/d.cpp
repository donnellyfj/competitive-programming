#include <bits/stdc++.h>
using namespace std;

// Polycarp Recovers the Permutation

void solve(int n, int k, set<int> vals) {
    int parity;
    int color;
    int mex = 0;
    int val = -1;
    int prevSize = n;

    while (vals.find(mex) != vals.end()) {
            mex++;
        }
    while (k--) {
        prevSize = vals.size();
        if (val == mex){
            while (vals.find(mex) != vals.end()) {
                mex++;
            }
        }
        if (mex > *vals.rbegin()) {
            cout << vals.size() + k + 1<< '\n';
            return;
        }
        // Add ceiling((mex + max) / 2) to set
        val = (mex + *vals.rbegin()) / 2 + ((mex + *vals.rbegin()) % 2 == 1);
        vals.insert(val);
        if (prevSize == vals.size()) {
            break; // No change in size means max and mex values have coverged to final value
        }
    }
    
    cout << vals.size() << '\n';
}

int main() {
    int t;
    int n;
    int k;
    int val;
    set<int> vals;

    // cout << "Input num of test cases: ";
    cin >> t;

    while (t--) {
        // cout << "Input array size: ";
        cin >> n >> k;
        // cout << "Input array: ";
        vals.clear();
        for (int idx = 0; idx < n; idx++) {
            cin >> val;
            vals.insert(val);
        }

        solve(n, k, vals);
    }
}
