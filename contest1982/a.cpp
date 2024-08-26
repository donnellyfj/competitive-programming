#include <bits/stdc++.h>
using namespace std;

// Soccer

void solve(int x1, int y1, int x2, int y2) {
    // Intuition: See if one team was losing and is now winning
    // Keep x1 <= y1 for consistency
    if (y1 < x1) {
        swap(x1, y1);
        swap(x2, y2);
    }
    if (x2 > y2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    int t;
    int x1, y1, x2, y2;

    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        solve(x1, y1, x2, y2);
    }

    return 0;
}
