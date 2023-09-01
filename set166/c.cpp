#include <bits/stdc++.h>
using namespace std;

// Sum of Two Numbers

int main() {
    int t;
    int n;
    int x;
    int y;
    int digit;
    int direction;
    int power;

    cin >> t;
    while (t--) {
        x = 0;
        y = 0;
        direction = 0;
        power = 0;
        cin >> n;

        // Intuition: Go digit by digit, split down the middle if even,
        //              otherwise alternate which side gets larger value
        while (n) {
            digit = n % 10;
            
            if (digit % 2 == 0) { // If digit is even, split evenly
                x += (digit / 2) * pow(10, power);
                y += (digit / 2) * pow(10, power);
            }
            else { // If digit is odd, send greater half to the side w smaller value
                if (direction % 2) {
                    x += (digit / 2 + 1) * pow(10, power);
                    y += (digit / 2) * pow(10, power);
                }
                else {
                    x += (digit / 2) * pow(10, power);
                    y += (digit / 2 + 1) * pow(10, power);
                }
                direction++;
            }
            n /= 10;
            power++;
        }
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
