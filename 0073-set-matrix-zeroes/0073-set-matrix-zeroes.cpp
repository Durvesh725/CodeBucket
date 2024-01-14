class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++)
                        ans[i][k]=0;
                    for(int l=0;l<m;l++)
                        ans[l][j]=0;
                }                     
            }
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=ans[i][j];
            }
        }
    }
};