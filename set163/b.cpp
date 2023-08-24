#include <bits/stdc++.h>
using namespace std;

// Not Dividing
 
void solve(int n, vector<int> nums){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            nums[i]++;
        }
    } 
    for (int i = 0; i < n - 1; i++) {
        while (nums[i + 1] % nums[i] == 0) {
            nums[i + 1]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << '\n';
}

int main() {
    // Prepare inputs and call solution
    int i;
    int n;
    vector<int> nums(0);
    
    cin >> i;
    while (i--) {
        cin >> n;
        nums.resize(n);
        for (int count = 0; count < n; count++) {
            cin >> nums[count];
        }
        
        solve(n, nums);
    }
}