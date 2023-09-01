#include <bits/stdc++.h>
using namespace std;

// Divisor Chain

int main() {
    int t;
    int x;
    int exp;
    vector<int> arr;

    cin >> t;
    while (t--) {
        cin >> x;
        arr.clear();

        // Intuition: Repeatedly subtract largest power of 2 that is less than the current value,
        //            and that evenly divides current value.
        while (x > 0) {
            exp = 2;
            while (x % exp == 0 && exp < x) {
                exp *= 2;
            }
            exp /= 2;

            arr.push_back(x);
            x -= exp;
        }
        cout << arr.size() << '\n';
        for (int i : arr) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
