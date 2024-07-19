class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int element = matrix[i][j];

                bool isMinRow = true;
                for(int k = 0; k < m; k++){
                    if(matrix[i][k] < element){
                        isMinRow = false;
                        break;
                    }
                }

                if(isMinRow){
                    bool isColMax = true;
                    for(int k = 0; k < n; k++){
                        if(matrix[k][j] > element){
                                isColMax = false;
                                break;
                            }
                        }
                        
                    if(isColMax){
                        ans.push_back(element);
                    }
                }
            }
        }
        return ans;
    }
};