#include <bits/stdc++.h>
using namespace std;

// Take a Guess

void solve(int n, int k) {
    // Intuition: Use the fact that a & b + a | b = a + b.
    vector<int> arr;

    // Get first three values
    int a;
    int b;
    int c;
    int orVal;
    int andVal;
    int temp1;
    int temp2;

    cout << "and 1 2\n";
    cin >> andVal;
    cout << "or 1 2\n";
    cin >> orVal;
    temp1 = andVal + orVal;
    cout << "and 1 3\n";
    cin >> andVal;
    cout << "or 1 3\n";
    cin >> orVal;
    temp2 = andVal + orVal;
    cout << "and 2 3\n";
    cin >> andVal;
    cout << "or 2 3\n";
    cin >> orVal;

    a = (temp1 + temp2 - (andVal + orVal)) / 2;
    b = temp1 - a;
    c = temp2 - a;
    arr = {a, b, c};

    // Get the rest of the values
    for(int i = 3; i < n; i++) {
        cout << "and " << i << " " << i + 1 << '\n';
        cin >> andVal;
        cout << "or " << i << " " << i + 1 << '\n';
        cin >> orVal;

        arr.push_back(andVal + orVal - arr.back());
    }

    sort(arr.begin(), arr.end());
    cout << "finish " << arr[k - 1] << '\n';
}

int main() {
    int t;
    int n;
    int k;
 
    cin >> n >> k;
    solve(n, k);
 
    return 0;
}
