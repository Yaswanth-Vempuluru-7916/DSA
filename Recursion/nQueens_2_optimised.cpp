#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans,
               vector<bool>& left_row, vector<bool>& upper_diagonal, vector<bool>& lower_diagonal) {
        if (col == n) {
            ans.push_back(board); // Add the current configuration to the solution
            return;
        }

        for (int row = 0; row < n; row++) {
            // Check if it's safe to place the queen
            if (!left_row[row] && !lower_diagonal[row + col] && !upper_diagonal[n - 1 + col - row]) {
                board[row][col] = 'Q'; // Place the queen
                left_row[row] = true; // Mark the row as used
                lower_diagonal[row + col] = true; // Mark the lower diagonal as used
                upper_diagonal[n - 1 + col - row] = true; // Mark the upper diagonal as used

                solve(col + 1, n, board, ans, left_row, upper_diagonal, lower_diagonal); // Recurse for next column

                // Backtrack
                board[row][col] = '.';
                left_row[row] = false;
                lower_diagonal[row + col] = false;
                upper_diagonal[n - 1 + col - row] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize the board with '.'

        // Boolean vectors to mark the left row and diagonals
        vector<bool> left_row(n, false), upper_diagonal(2 * n - 1, false), lower_diagonal(2 * n - 1, false);

        solve(0, n, board, ans, left_row, upper_diagonal, lower_diagonal); // Start solving from the 0th column
        return ans;
    }
};

int main() {
    int n = 4; // Example with a 4x4 board
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
