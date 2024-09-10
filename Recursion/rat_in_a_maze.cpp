#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*

Time Complexity (TC):
The time complexity for the solution is governed by how many possible paths we explore and the work done at each step.

Exploring all possible paths:
For each cell, we can move in 4 possible directions: Up, Down, Left, Right.
In the worst case, we explore every possible combination of moves, which results in O(4^(n^2)). Here, n^2 represents the total number of cells in an n x n grid.
Backtracking:
Each path exploration either leads to a solution or backtracks to try another path. On average, we prune paths by not revisiting already visited cells.
However, in the worst case (if all paths are valid), we will still explore all possibilities, leading to exponential time complexity.
Therefore, the worst-case time complexity is:

O(4^(n^2)).

Space Complexity (SC):
The space complexity includes:

Visited matrix:

We use a 2D visited array to keep track of cells we've already visited. This matrix has n^2 elements, so it requires O(n^2) space.
Recursion stack:

The depth of the recursion tree is proportional to the number of cells (i.e., at most n^2 recursive calls).
The space required by the recursion stack in the worst case is O(n^2).
Result storage:

We store all the valid paths in the ans vector. The number of paths is bounded by how many unique paths exist, and each path can have up to 2n-2 characters (in a worst-case scenario where we traverse the full grid). This means storing the results requires O(K * (2n-2)) space, where K is the number of valid paths.
Thus, the overall space complexity is:

O(n^2) for the visited matrix and recursion stack, plus O(K * (2n-2)) for storing the paths.


Final Complexity:
Time Complexity: O(4^(n^2)) (in the worst case).
Space Complexity: O(n^2) (for visited matrix and recursion stack) + O(K * (2n-2)) for storing results.

*/
void solve(vector<vector<int>> &mat, int i, int j, vector<vector<bool>> &visited, string path, int n, vector<string> &ans)
{
    // Base case: if we reach the destination cell (n-1, n-1)
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }
//Okavela path ni by refernce pass chesthe
// path = path +'D'
//After the returning of the recursion
//path.pop_back()
    // DOWN
    if (i + 1 < n && !visited[i + 1][j] && mat[i + 1][j] == 1)
    {
        visited[i][j] = true;
        solve(mat, i + 1, j, visited, path + "D", n, ans);
        visited[i][j] = false;
    }

    // LEFT
    if (j - 1 >= 0 && !visited[i][j - 1] && mat[i][j - 1] == 1)
    {
        visited[i][j] = true;
        solve(mat, i, j - 1, visited, path + "L", n, ans);
        visited[i][j] = false;
    }

    // RIGHT
    if (j + 1 < n && !visited[i][j + 1] && mat[i][j + 1] == 1)
    {
        visited[i][j] = true;
        solve(mat, i, j + 1, visited, path + "R", n, ans);
        visited[i][j] = false;
    }

    // UP
    if (i - 1 >= 0 && !visited[i - 1][j] && mat[i - 1][j] == 1)
    {
        visited[i][j] = true;
        solve(mat, i - 1, j, visited, path + "U", n, ans);
        visited[i][j] = false;
    }
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    int n = mat.size();

    // Edge case: If starting point is blocked (mat[0][0] == 0), no path exists

    if (mat[0][0] == 0)
        return ans;

    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // Start the pathfinding from the top-left corner (0, 0)
    solve(mat, 0, 0, visited, path, n, ans);

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 1}};

    vector<string> result = findPath(mat);

    if (result.empty())
    {
        cout << "No path found." << endl;
    }
    else
    {
        cout << "Paths found: " << endl;
        for (const string &path : result)
        {
            cout << path << endl;
        }
    }

    return 0;
}
