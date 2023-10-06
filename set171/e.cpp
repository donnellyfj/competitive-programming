#include <bits/stdc++.h>
using namespace std;
 
// Andrew and Stones
 
void solve(int n, vector<int> arr) {
    // Intuition: First determine if you can make all piles between the first and last even.
    //            If you can, add up and print the number of moves. Otherwise print -1.
    long long int out = 0;
    vector<int> ones;
    vector<int> odds;
    vector<int> evens;

    // Check if you can make all piles even
    // Find indices of piles equal to 1, odd greater than 1, and even
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] == 1) {
            ones.push_back(arr[i]);
        }
        else if (arr[i] > 1 and arr[i] % 2) {
            odds.push_back(arr[i]);
        }
        else if (arr[i] > 0 and arr[i] % 2 == 0) {
            evens.push_back(arr[i]);
        }
    }

    // If there are any ones, add to them with one of the odd numbers greater than 1
    while (!ones.empty() && !odds.empty()) {
        // Remove 1 from array
        ones.pop_back();
        // Update arrays
        evens.push_back(2);
        odds.back() -= 2;
        if (odds.back() == 1) {
            odds.pop_back();
            ones.push_back(1);
        }
        out += 1;
    }
    // If there are still any ones, add to them with one of the even numbers
    while (!ones.empty() && !evens.empty()) {
        // Remove 1 from array
        ones.pop_back();
        // Update arrays
        evens.push_back(2);
        evens.back() -= 2;
        if (evens.back() == 0) {
            evens.pop_back();
        }
        out += 1;
    }
    // If there are still any ones, print -1
    if (!ones.empty()) {
        cout << -1 << '\n';
        return;
    }

    // If there are any odds, add to them with one of the even numbers
    while (!odds.empty() && !evens.empty()) {
        // Remove odd value from array
        int newVal = odds.back() + 1;
        odds.pop_back();
        // Update arrays
        evens.push_back(newVal);
        evens.back() -= 2;
        if (evens.back() == 0) {
            evens.pop_back();
        }
        out += 1;
    }
    // If there is only one odd left, print -1
    if (odds.size() == 1) {
        cout << -1 << '\n';
        return;
    }

    // If there are only odds left, add 1 to each and add them to the evens, since the # of moves is the same
    while (!odds.empty()) {
        evens.push_back(odds.back() + 1);
        odds.pop_back();
    }

    // Now that there are all even numbers, add up the amount of operations needed
    for (int val : evens) {
        out += val / 2;
    }

    cout << out << '\n';
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
