//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        //1. mark visited
        vis[row][col] = 1;
        
        //2. push first ele
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int n = grid.size();
        int m = grid[0].size(); 
        
        while(!q.empty()){
            //get first ele
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //traverse neigh: 8 directions, delrow and delcol logic
            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <=1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    //check if the nrow and ncol idx is not out of bounds (visit neighbours)
                    if(nrow >=0 && nrow <n && ncol >=0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }   
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        //S1: created visited matrix
        int n = grid.size();
        int m = grid[0].size();
        //vis matrix
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends