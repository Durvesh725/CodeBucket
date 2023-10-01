//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> ans;
        
        //first row
        for(int j = 0; j < m; j++){
            ans.push_back(matrix[0][j]);
        }
        
        //last col
        for(int i = 1; i < n; i++){
            ans.push_back(matrix[i][m-1]);
        }
        
        //last row
        if(n>1){
            for(int j = m-2; j >= 0; j--){
                ans.push_back(matrix[n-1][j]);
            }   
        }
        
        //first row
        if(m>1){
            for(int i = n-2; i > 0; i--){
                ans.push_back(matrix[i][0]);
            }   
        }
        
        // //first row
        // for(int i = 0; i < 1; i++){
        //     for(int j = 0; j < m-1; j++){
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        
        // //last col
        // for(int i = 0; i < n-1; i++){
        //     for(int j = m-1; j <= m-1; j++){
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        
        // //last row
        // for(int i = n-1; i <= n-1; i++){
        //     for(int j = m-1; j > 0; j--){
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        
        // //first col
        // for(int i = n-1; i > 0; i--){
        //     for(int j = 0; j <= 0; j++){
        //         ans.push_back(matrix[i][j]);
        //     }
        // }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends