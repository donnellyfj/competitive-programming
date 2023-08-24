#include <bits/stdc++.h>
using namespace std;

// MAX-MEX Cut

void solve(int n, vector<char> arr1, vector<char> arr2) {
    int out = 0;
    int cut = 0;


    while (cut < n) {
        // Case 1: [10] or [01] -> add 2 to sum
        //         [10]    [01]
        if (cut + 2 <= n && arr1[cut] == arr2[cut] && arr1[cut + 1] == arr2[cut + 1] && arr1[cut] != arr1[cut + 1]) {
            out += 2;
            cut += 2;
        }
        // Case 2: [1] or [0] -> add 2 to sum
        //         [0]    [1]
        else if (arr1[cut] != arr2[cut]) {
            out += 2;
            cut += 1;
        }
        // Case 3: [0] -> add 1 to sum
        //         [0] 
        else if (arr1[cut] == arr2[cut] && arr1[cut] == '0') {
            out += 1;
            cut += 1;
        }
        // Case 4: [1] -> add 0 to sum
        //         [1] 
        else if (arr1[cut] == arr2[cut] && arr1[cut] == '1') {
            cut += 1;
        }
    }

    
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    vector<char> arr1;
    vector<char> arr2;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size: ";
        scanf("%d", &n);
        arr1.resize(n + 1);
        arr2.resize(n + 1);
        // cout << "Input array: ";
        for (int idx = 0; idx < n + 1; idx++) {
            scanf("%c", &arr1[idx]);
        }
        arr1.erase(arr1.begin()); // Remove \n from beginning

        for (int idx = 0; idx < n + 1; idx++) {
            scanf("%c", &arr2[idx]);
        }
        arr2.erase(arr2.begin()); // Remove \n from beginning

        solve(n, arr1, arr2);
    }
}
