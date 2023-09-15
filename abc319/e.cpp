#include <bits/stdc++.h>
using namespace std;

// Bus Stops

long long int rideBuses(long long int start, vector<long long int> p, vector<long long int> t) {
    long long int end = start;

    for (long long int i = 0; i < size(p); i++) {
        // Find next bus arrival
        if (end % p[i] != 0) {
            end += p[i] - end % p[i];
        }

        // Ride bus
        end += t[i];
    }

    return end;
}

int main() {
    long long int n, x, y;
    cin >> n >> x >> y;

    vector<long long int> p(n - 1);
    vector<long long int> t(n - 1);
    
    // Get Inputs
    for (long long int i = 0; i < n - 1; i++) {
        cin >> p[i] >> t[i];
    }

    long long int qLen;
    cin >> qLen;
    vector<long long int> q(qLen);
    
    for (long long int i = 0; i < qLen; i++) {
        cin >> q[i];
    }

    // Intuition: Precompte all possible times, since they will repeat
    //            with a period of LCM(p)
    // Find LCM
    long long int period = 1;
    for (long long int i : p) {
        period = lcm(period, i);
    }

    // Precompute all possible times
    vector<long long int> times(period);
    for (long long int startTime = 0; startTime < period; startTime++) {
        times[startTime] = rideBuses(startTime + x, p, t) + y;
    }

    // time(q) = beginning of most recent period + time(q % period)
    for (long long int i = 0; i < qLen; i++) {
        cout << q[i] - (q[i] % period) + times[q[i] % period] << '\n';
    }

    return 0;
}
