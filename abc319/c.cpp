#include <bits/stdc++.h>
using namespace std;

// False Hope

int main() {
    vector<vector<int>> coords = {{0, 1, 2},
                                  {3, 4, 5},
                                  {6, 7, 8}};

    vector<int> order(9);
    iota(order.begin(), order.end(), 0);
    int nineFact = 1;
    for (int i = 1; i <= 9; i++) {
        nineFact *= i;
    }

    // Get input
    vector<int> vals(9);
    for (int i = 0; i < 9; i++) {
        cin >> vals[i];
    }

    int counter = nineFact;
    double disappointCount = 0;
    vector<int> view(9);
    bool flag = false;
    while (counter--) {
        fill(view.begin(), view.end(), 0);

        flag = false;
        for (int i = 0; i < 9; i++) {
            // Reveal the next number
            view[order[i]] = vals[order[i]];
            
            // If one value in a line is zero and two values are nonzero and equal
            // Check verticals
            for (int col = 0; col < 3; col++) {
                // First two
                if (view[coords[0][col]] != 0 && view[coords[0][col]] == view[coords[1][col]] && view[coords[2][col]] == 0) {
                    flag = true;
                }
                // Last two
                else if (view[coords[1][col]] != 0 && view[coords[1][col]] == view[coords[2][col]] && view[coords[0][col]] == 0) {
                    flag = true;
                }
                // First and Last
                else if (view[coords[0][col]] != 0 && view[coords[0][col]] == view[coords[2][col]] && view[coords[1][col]] == 0) {
                    flag = true;
                }
            }

            // Check horizontals
            for (int row = 0; row < 3; row++) {
                // First two
                if (view[coords[row][0]] != 0 && view[coords[row][0]] == view[coords[row][1]] && view[coords[row][2]] == 0) {
                    flag = true;
                }
                // Last two
                else if (view[coords[row][1]] != 0 && view[coords[row][1]] == view[coords[row][2]] && view[coords[row][0]] == 0) {
                    flag = true;
                }
                // First and Last
                else if (view[coords[row][0]] != 0 && view[coords[row][0]] == view[coords[row][2]] && view[coords[row][1]] == 0) {
                    flag = true;
                }
            }

            // Check top left -> bottom right diagonal
            // First two
            if (view[coords[0][0]] != 0 && view[coords[0][0]] == view[coords[1][1]] && view[coords[2][2]] == 0) {
                flag = true;
            }
            // Last two
            else if (view[coords[1][1]] != 0 && view[coords[1][1]] == view[coords[2][2]] && view[coords[0][0]] == 0) {
                flag = true;
            }
            // First and Last
            else if (view[coords[0][0]] != 0 && view[coords[0][0]] == view[coords[2][2]] && view[coords[1][1]] == 0) {
                flag = true;
            }

            // Check top right -> bottom left diagonal
            // First two
            if (view[coords[0][2]] != 0 && view[coords[0][2]] == view[coords[1][1]] && view[coords[2][0]] == 0) {
                flag = true;
            }
            // Last two
            else if (view[coords[1][1]] != 0 && view[coords[1][1]] == view[coords[2][0]] && view[coords[0][2]] == 0) {
                flag = true;
            }
            // First and Last
            else if (view[coords[0][2]] != 0 && view[coords[0][2]] == view[coords[2][0]] && view[coords[1][1]] == 0) {
                flag = true;
            }

            if (flag) {
                break;
            }
        }

        disappointCount += flag;
        next_permutation(order.begin(), order.end());
    }

    cout << setprecision(10) << (nineFact - disappointCount) / nineFact << '\n';

    return 0;
}
