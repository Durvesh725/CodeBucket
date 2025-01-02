class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> &vis, int &m, int &n){
        queue<pair<int, int>> q;
        vis[sr][sc] = 1;
        q.push({sr, sc});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && image[nrow][ncol] == image[sr][sc]){
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        if(image[sr][sc] != color)
            bfs(image, sr, sc, color, vis, m, n);

        image[sr][sc] = color;

        return image;
    }
};