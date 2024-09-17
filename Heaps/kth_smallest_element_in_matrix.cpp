#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int mat[MAX][MAX];

// Function to find the kth smallest element in a row-wise and column-wise sorted matrix
// Time Complexity: O(n^2 log k), where n is the dimension of the matrix and k is the index of the smallest element
// Space Complexity: O(k), as we maintain a max-heap of size k
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    priority_queue<int> maxHeap; // Max-Heap to keep track of the smallest elements

    // Insert the first k elements into the max-heap
    int cnt = k, ii, jj;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (cnt) {
                maxHeap.push(mat[i][j]);
                cnt--;
            } else {
                break;
            }
        }

        if (cnt == 0) {
            ii = i;
            jj = j;
            break;
        }
    }

    // Process the remaining elements in the matrix
    for (int i = ii; i < n; i++) {
        for (int j = (i == ii ? jj : 0); j < n; j++) {
            if (mat[i][j] < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(mat[i][j]);
            }
        }
    }

    return maxHeap.top(); // The kth smallest element is at the top of the max-heap
}

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    return 0;
}
