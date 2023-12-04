#include <bits/stdc++.h>
using namespace std;
 
// Mr. Perfectly Fine

void solve(int n, vector<int> skill1, vector<int> skill2, vector<int> skill12) {
    // Intuition: Separate by skills, sort based on time.
    sort(skill1.begin(), skill1.end());
    sort(skill2.begin(), skill2.end());
    sort(skill12.begin(), skill12.end());

    int out;
    if (skill1.empty() || skill2.empty()) {
        if (skill12.empty()) {
            out = -1;
        }
        else {
            out = skill12[0];
        }
    }
    else if (skill12.empty()) {
        out = skill1[0] + skill2[0];
    }
    else {
        out = min(skill1[0] + skill2[0], skill12[0]);
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    vector<int> skill1;
    vector<int> skill2;
    vector<int> skill12;
 
    cin >> t;
    while (t--) {
        cin >> n;
        skill1.clear();
        skill2.clear();
        skill12.clear();
        int time;
        int skills;
        for (int i = 0; i < n; i++) {
            cin >> time >> skills;
            if (skills == 10) {
                skill1.push_back(time);
            }
            else if (skills == 1) {
                skill2.push_back(time);
            }
            else if (skills == 11) {
                skill12.push_back(time);
            }
        }
        solve(n, skill1, skill2, skill12);
    }
 
    return 0;
}
