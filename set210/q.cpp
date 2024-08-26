#include <bits/stdc++.h>
using namespace std;

// Reverse and Swap

int arrSize;
vector<long long int> arr;
vector<vector<int>> queries;
long long int idxMod = 0;
vector<long long int> tree;
vector<bool> swapped;

// Segment tree utility functions
void buildTree(int currNode, int l, int r) {
    if (l == r) {
        tree[currNode] = arr[l];
    }
    else {
        int m = (l + r) / 2;
        int leftChild = (currNode + 1) * 2 - 1;
        int rightChild = (currNode + 1) * 2;
        buildTree(leftChild, l, m);
        buildTree(rightChild, m + 1, r);
        tree[currNode] = tree[leftChild] + tree[rightChild];
    }
}

void update(int currNode, int l, int r, int updateIdx, int updateVal) {
    if (l == r) {
        tree[currNode] = updateVal;
    }
    else {
        int m = (l + r) / 2;
        int leftChild = (currNode + 1) * 2 - 1;
        int rightChild = (currNode + 1) * 2;
        // Swap children if the next power of 2 has been swapped/reversed
        if (swapped[log2((r - l + 1) / 2)]) {
            swap(leftChild, rightChild);
        }
        if (updateIdx <= m) {
            update(leftChild, l, m, updateIdx, updateVal);
        }
        else {
            update(rightChild, m + 1, r, updateIdx, updateVal);
        }
        tree[currNode] = tree[leftChild] + tree[rightChild];
    }
}

long long int getSum(int currNode, int l, int r, int sumL, int sumR) {
    if (sumL > sumR) {
        return 0;
    }
    if (l == sumL && r == sumR) {
        return tree[currNode];
    }
    int m = (l + r) / 2;
    int leftChild = (currNode + 1) * 2 - 1;
    int rightChild = (currNode + 1) * 2;
    // Swap children if the next power of 2 has been swapped/reversed
    if (swapped[log2((r - l + 1) / 2)]) {
        swap(leftChild, rightChild);
    }

    long long int leftSum = getSum(leftChild, l, m, sumL, min(m, sumR));
    long long int rightSum = getSum(rightChild, m + 1, r, max(m + 1, sumL), sumR);
    return leftSum + rightSum;
}

void solve(long long int n, long long int q) {
    // Intuition: Swap seg tree children based on queries
    // Build seg tree
    buildTree(0, 0, arrSize - 1);
    // Parse queries
    for (vector<int> currQ : queries) {
        if (currQ[0] == 1) {
            // Replace
            update(0, 0, arrSize - 1, currQ[1] - 1, currQ[2]);
        }
        else if (currQ[0] == 2) {
            // Reverse is a swap of all powers < k
            for (int i = 0; i < currQ[1]; i++) {
                swapped[i] = !swapped[i];
            }
        }
        else if (currQ[0] == 3) {
            // Swap
            swapped[currQ[1]] = !swapped[currQ[1]];
        }
        else if (currQ[0] == 4) {
            // Sum
            cout << getSum(0, 0, arrSize - 1, currQ[1] - 1, currQ[2] - 1) << '\n';
        }
    }
}

int main() {
    long long int n;
    long long int q;
    int temp1;
    int temp2;
    int temp3;

    cin >> n >> q;
    arrSize = 1 << n;
    arr.resize(arrSize);
    tree.resize(arrSize * 4);
    swapped = vector<bool>(arrSize * 4, false);
    queries.resize(q);
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> temp1;
        if (temp1 == 1 || temp1 == 4) {
            cin >> temp2 >> temp3;
            queries[i] = {temp1, temp2, temp3};
        }
        else {
            cin >> temp2;
            queries[i] = {temp1, temp2};
        }
    }

    solve(n, q);

    return 0;
}
