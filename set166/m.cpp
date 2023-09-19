#include<bits/stdc++.h>

using namespace std;

// Different Arrays

const int MOD = 998244353;
const int ZERO = 90000; // Offset to avoid negative indices
// Keep track of existing states
// dp[0] -> current state, dp[1] -> next state
int dp[2][ZERO * 2];

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}   


void performOperations(int origVal)
{
    // Clear next state
    for(int i = 0; i < ZERO * 2; i++)
        dp[1][i] = 0;

    // Loop through all possible values
    for(int i = 0; i < ZERO * 2; i++)
    {
        // If there doesn't exist a state at this value, skip to next value
        if(dp[0][i] == 0) continue;

        // Next value = current value +/- original value
        int nextVal = origVal + i;
        // Perform add operation
        dp[1][nextVal] = add(dp[1][nextVal], dp[0][i]);

        // If next value isn't zero, perform subtract operation
        if(nextVal != ZERO) {
            dp[1][2 * ZERO - nextVal] = add(dp[1][2 * ZERO - nextVal], dp[0][i]);
        }
    }

    // Set current state = next state
    for(int i = 0; i < ZERO * 2; i++)
        dp[0][i] = dp[1][i];
}

int main()
{
    // Get inputs
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    // Current state: initial array
    dp[0][ZERO] = 1;

    // Perform both operations for every value in the array except
    // for the first and last values, since they aren't used
    for(int i = 1; i + 1 < n; i++) {
        performOperations(a[i]);
    }
    
    // Count number of existing states
    int ans = 0;
    for(int i = 0; i < ZERO * 2; i++)
        ans = add(ans, dp[0][i]);
    cout << ans << endl;
}
