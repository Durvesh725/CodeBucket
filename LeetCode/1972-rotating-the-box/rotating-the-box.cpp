class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> rotatedBox(n, vector<char>(m, '0'));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = box[i][j];
            }
        }

        for(int j = 0; j < m; j++){
            int emptyPos = n-1;

            for(int i = n-1; i >= 0; i--){
                if(rotatedBox[i][j] == '*')
                    emptyPos = i - 1;

                else if(rotatedBox[i][j] == '#'){
                    rotatedBox[i][j] = '.';
                    rotatedBox[emptyPos][j] = '#';
                    emptyPos--;
                }
            }
        }

        return rotatedBox;
    }
};