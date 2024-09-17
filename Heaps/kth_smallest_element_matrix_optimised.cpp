#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int mat[MAX][MAX];

// Function to find the kth smallest element in a row-wise and column-wise sorted matrix
// Time Complexity: O(k log n), where n is the number of rows and k is the index of the smallest element
// Space Complexity: O(n), as we maintain a min-heap of size n
int kthSmallest(int mat[MAX][MAX], int n, int k) {
  // Step 1: Create a min-heap (priority_queue) to store matrix elements
  // Min-heap stores (element value, (row index, column index))
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;
 
  // Step 2: Initialize the heap with the first element from each row (smallest element of each row)
  for (int i = 0; i < n; i++) {
    p.push({mat[i][0], {i, 0}});
  }

  // Step 3: Extract the smallest element from the heap `k` times
  pair<int, pair<int, int>> element;
  int data, i, j;
  while (k--) {
    // Extract the smallest element (which is at the top of the min-heap)
    element = p.top();
    p.pop();

    // Store the smallest value in `data`
    data = element.first;
    i = element.second.first; // Row index of the extracted element
    j = element.second.second; // Column index of the extracted element

    // Step 4: If there is a next element in the same row, push it into the heap
    if (j + 1 < n) {
      p.push({mat[i][j + 1], {i, j + 1}});
    }
  }

  // Step 5: Return the k-th smallest element, which is stored in `data`
  return data;
}

// Driver code to test the solution
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