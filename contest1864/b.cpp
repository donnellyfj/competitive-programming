#include <bits/stdc++.h>
using namespace std;

// Swap and Reverse

int main() {
    int t;
    int n;
    int k;
    string str;
    string even;
    string odd;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        cin >> n >> k;
        str.resize(n);

        // Intuition: If k is even, swap/reverse rules allow you to just sort the strings.
        //            If k is odd, sort even/odd indices separately and then merge.
        cin >> str;
        if (k % 2 == 0) {
            sort(str.begin(), str.end());
            cout << str;
        }
        else {
            even.clear();
            odd.clear();
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    odd.push_back(str[i]);
                }
                else {
                    even.push_back(str[i]);
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    cout << odd[i / 2];
                }
                else {
                    cout << even[i / 2];
                }
            }
        }
        cout << '\n';
    }
}
