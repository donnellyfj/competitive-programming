#include <bits/stdc++.h>
using namespace std;
 
// Garage
 
void solve(long long int n) {
    // Intuition: Since b is the hypotenuse, Pythagorean thrm says a^2 + c^2 = b^2. We want to solve
    //            for c^2 as the area of the square, so c^2 = b^2 - a^2. Reworking into c^2 = (a + x)^2 - a^2
    //            and observing possible outputs for x = 1 and 2, and noting that even #s not divisble by 4 are
    //            not valid, we can see that all possible values are odd #s >= 3 and #s divisible by 4 >= 8.
    //            This set of numbers effectively skips every 3 numbers, which we can simulate with 4n / 3.
    if (n == 1) {
        cout << 3 << '\n';
    }
    else if (n == 2){
        cout << 5 << '\n';
    }
    else {
        cout << (4 * n) / 3 + 3 << '\n';
    }
}
 
int main() {
    long long int n;
 
    cin >> n;
    solve(n);
 
    return 0;
}
