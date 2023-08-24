#include <bits/stdc++.h>
using namespace std;

// Mark the Photographer
 
void solve(int n, int x, vector<int> heights){
    sort(heights.begin(), heights.end());
    for (int i = 0; i < n; i++) {
        if (heights[i + n] - heights[i] < x) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}
 
int main() {
    // Prepare inputs and call solution
    int i;
    int n;
    int x;
    vector<int> heights(0);
    cout << "starting..." << '\n';
    
    cin >> i;
    while (i--) {
        cin >> n;
        cin >> x;
        heights.resize(n * 2);
        for (int count = 0; count < n * 2; count++) {
            cin >> heights[count];
        }
        
        solve(n, x, heights);
    }
}