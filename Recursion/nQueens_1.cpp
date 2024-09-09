#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int tempRow = row;
        int tempCol = col;

        // Check left row
        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }

        row = tempRow;
        col = tempCol;

        // Check upper diagonal
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }

        row = tempRow;
        col = tempCol;

        // Check lower diagonal
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; // Place the queen
                solve(col + 1, n, board, ans); // Solve for the next column
                board[row][col] = '0'; // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '0'); // Create a string of '.' with length n

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(0, n, board, ans); // Start solving from the 0th column
        return ans;
    }
};

int main() {
    int n = 7; // We are taking 4x4 grid and 4 queens as an example
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);

    for (int i = 0; i < ans.size(); i++) {
        cout << "Arrangement " << i + 1 << ":\n";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}
