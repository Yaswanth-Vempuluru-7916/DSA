#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<vector<int>> &mat, int i, int j, vector<vector<bool>> &visited, string path, int n, vector<string> &ans,  vector<int>di,  vector<int>dj)
{
    // Base case: if we reach the destination cell (n-1, n-1)
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    string direction = "DLRU";

    for(int ind = 0;ind<4;ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && !visited[nexti][nextj] && mat[nexti][nextj]==1){
            visited[i][j]=true;
            solve(mat,nexti,nextj,visited,path+direction[ind],n,ans,di,dj);
            visited[i][j]=false;
        }
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
    vector<int>di{1,0,0,-1};
    vector<int>dj{0,-1,1,0};
    // Start the pathfinding from the top-left corner (0, 0)
    solve(mat, 0, 0, visited, path, n, ans,di,dj);

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
