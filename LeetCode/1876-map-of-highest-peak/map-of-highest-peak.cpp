class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> res(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(isWater[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        vector<int> rowarr = {-1,0,+1,0};
        vector<int> colarr = {0,+1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + rowarr[i];
                int ncol = c + colarr[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1){
                    vis[nrow][ncol] = 1;
                    res[nrow][ncol] = res[r][c] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return res;
    }
};