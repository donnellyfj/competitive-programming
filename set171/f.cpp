#include <bits/stdc++.h>
using namespace std;
 
// Minimize Distance

long long int travel(int k, vector<int> arr) {
    long long out = 0;
    int bags = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (bags > 1) {
            bags--;
            continue;
        }
        out += arr[i] * 2;
        bags = k;
    }
    return out;
}
 
void solve(int n, int k, vector<int> arr) {
    // Intuition: Sort values, split by sign, and then only count 1 out of every k depots, starting with the max.
    // Sort values
    vector<int> negArr(arr.begin(), arr.end());
    sort(negArr.begin(), negArr.end());
    long long int out = 0;

    // Split array into positive and negative values
    vector<int> posArr;
    while (!negArr.empty() && negArr.back() > 0) {
        posArr.push_back(negArr.back());
        negArr.pop_back();
    }

    if (posArr.empty()) {
        posArr.push_back(0);
    }
    if (negArr.empty()) {
        negArr.push_back(0);
    }

    // Reformat negative array to be positive values
    for (int i = 0; i < negArr.size(); i++) {
        negArr[i] *= -1;
    }

    // Traverse array with smaller max first
    if (posArr[0] < negArr[0]) {
        swap(posArr, negArr);
    }
    out += travel(k, negArr);
    out += travel(k, posArr);
    out -= posArr[0];

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    int k;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> k;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, k, arr);
    }
 
    return 0;
}
