#include <bits/stdc++.h>
using namespace std;

// Dogeforces

int n;
vector<vector<int>> arr;
vector<int> salaries;
vector<pair<int, int>> supervisors;

int calc(vector<int> leaves) {
    // Stop recursion if only one leaf node in the current subtree
    if (leaves.size() == 1) {
        return leaves[0];
    }

    // Find root of current subtree
    int maxSalary = -1;
    for (int leaf : leaves) {
        maxSalary = max(maxSalary, arr[leaves[0]][leaf]);
    }

    vector<vector<int>> subtrees;
    subtrees.push_back({leaves[0]});
    // Loop through each leaf in current subtree
    for (int i = 1; i < leaves.size(); i++) {
        // Salary of current employee
        int curr = leaves[i];
        int subtree = -1;
        for (int j = 0; j < subtrees.size(); j++) {
            // If two nodes have a supervisor (lowest common ancestor) that isn't
            // the current root node, then they belong to the same subtree
            if (arr[curr][subtrees[j][0]] != maxSalary) {
                subtree = j;
                break;
            }
        }
        // If current node doesn't belong to any current subtree, make a new subtree
        if (subtree == -1) {
            subtree = subtrees.size();
            subtrees.push_back({});
        }
        subtrees[subtree].push_back(curr);
    }
    // Update total number of employees for new supervisor found as well as its salary
    int curr = n++;
    salaries[curr] = maxSalary;
    // Find direct employees of current root
    for (int i = 0; i < subtrees.size(); i++) {
        int employee = calc(subtrees[i]);
        supervisors.push_back({employee, curr});
    }
    return curr;
}

void solve(vector<vector<int>> arr) {
    // Intuition: Build employee/supervisor relations recursively by subtree
    vector<int> leaves;
    salaries.resize(2 * n);
    leaves.resize(n);

    // Get salaries for each worker
    for (int i = 0; i < n; i++) {
        salaries[i] = arr[i][i];
    }
    iota(leaves.begin(), leaves.end(), 0);
    // Calculate employees/supervisors
    int head = calc(leaves);
    
    // Output number of employees
    cout << n << '\n';
    // Output salaries
    for (int i = 0; i < n; i++) {
        cout << salaries[i] << ' ';
    }
    // Output head of the company
    cout << '\n' << head + 1 << '\n';
    // Output employee/supervisor pairs
    for (pair<int, int> curr : supervisors) {
        cout << curr.first + 1 << ' ' << curr.second + 1 << '\n';
    }
}
 
int main() {
    cin >> n;
    arr.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    solve(arr);

    return 0;
}
