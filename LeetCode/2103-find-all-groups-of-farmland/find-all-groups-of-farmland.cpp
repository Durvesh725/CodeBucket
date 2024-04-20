class Solution {
public:
    int row_arr[4] = {-1, 0, 1, 0};
    int col_arr[4] = {0, 1, 0, -1};
    int lastx = -1;
    int lasty = -1;

    void bfs(vector<vector<int>>& land, int row, int col, vector<vector<int>> &vis, int &n, int &m){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            lastx = r;
            lasty = c;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + row_arr[k];
                int nc = c + col_arr[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && land[nr][nc] == 1){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int startx = 0; startx < n; startx++){
            for(int starty = 0; starty < m; starty++){
                if(land[startx][starty] == 1 && !vis[startx][starty]){
                    lastx = startx;
                    lastx = starty;
                    bfs(land, startx, starty, vis, n, m);
                    ans.push_back({startx, starty, lastx, lasty});
                }
            }
        }
        return ans;
    }
};