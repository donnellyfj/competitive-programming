#include <bits/stdc++.h>
using namespace std;
 
// Groups

bool helper(int n, int day1, int day2, vector<vector<int>> arr) {
    vector<int> d1List;
    vector<int> d2List;
    vector<int> bothList;

    for (int i = 0; i < n; i++) {
        // If a student can't make either day, return false
        if (arr[i][day1] == 0 && arr[i][day2] == 0) {
            return false;
        }
        // Check if student can make both days
        else if (arr[i][day1] == 1 && arr[i][day2] == 1) {
            bothList.push_back(i);
        }
        // Check if student can only make one of the days
        else if (arr[i][day1] == 1) {
            d1List.push_back(i);
        }
        else {
            d2List.push_back(i);
        }
    }

    // Check if sizes of d1 and d2 lists can be made equal
    int d1Size = d1List.size();
    int d2Size = d2List.size();
    if (abs(d1Size - d2Size) <= bothList.size()) {
        return true;
    }
    else {
        return false;
    }
}
 
void solve(int n, vector<vector<int>> arr) {
    // Intuition: Select all pairs of days and try to split them into equal groups.
    for (int i = 0; i < 5 - 1; i ++) {
        for (int j = i + 1; j < 5; j++) {
            if (helper(n, i, j, arr)) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}
 
int main() {
    int t;
    int n;
    int x;
    vector<vector<int>> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i].resize(5);
            for (int j = 0; j < 5; j++) {
                cin >> arr[i][j];
            }
        }

        solve(n, arr);
    }
 
    return 0;
}
