#include <bits/stdc++.h>
using namespace std;
 
// Perfect Permutation
 
void solve(int n) {
    // Intuition: Rotate array one to the left. Let a = [1 2 3 ... n] (the indices of the array),
    //            and b also = [1 2 3 ... n]. Rotating b to the left once will give a weight of 1,
    //            since if a evenly divides b, then a won't be able to evenly divide b - 1, unless a = 1.

    // Print array rotated once to the left.
    for (int i = 1; i < n; i++) {
        cout << i + 1 << " ";
    }
    cout << 1 << '\n';
}
 
int main() {
    int t;
    int n;
 
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
 
    return 0;
}
