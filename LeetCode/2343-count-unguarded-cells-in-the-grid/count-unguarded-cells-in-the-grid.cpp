class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, -1));

        for(auto x: guards){
            grid[x[0]][x[1]] = 1;
        }

        for(auto x: walls){
            grid[x[0]][x[1]] = 2;
        }

        for(auto x: guards){
            //up
            int i = x[0], j = x[1];
            i--;
            while(i >= 0 && grid[i][j] != 1 && grid[i][j] != 2){
                grid[i][j] = 3;
                i--;
            }

            //down
            i = x[0];
            i++;
            while(i < m && grid[i][j] != 1 && grid[i][j] != 2){
                grid[i][j] = 3;
                i++;
            }

            //left
            i = x[0], j = x[1];
            j--;
            while(j >= 0 && grid[i][j] != 1 && grid[i][j] != 2){
                grid[i][j] = 3;
                j--;
            }

            //right
            j = x[1];
            j++;
            while(j < n && grid[i][j] != 1 && grid[i][j] != 2){
                grid[i][j] = 3;
                j++;
            }
        }

        int ans = 0;
        for(auto x: grid){
            for(auto y: x){
                if(y == -1) ans++;
            }
        }

        return ans;
    }
};