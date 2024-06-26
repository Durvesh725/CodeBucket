class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int mt = 0;
        int row_arr[4] = {-1, 0, +1, 0};
        int col_arr[4] = {0, 1, 0, -1};
        int markRotten = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            mt = max(mt, t);
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + row_arr[k];
                int nc = c + col_arr[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc] = 2;
                    //mark rotten
                    markRotten++;
                }
            }
        }

        if(cntFresh != markRotten)  return -1;
        
        return mt;
    }
};