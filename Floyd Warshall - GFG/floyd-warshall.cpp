//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    //Before
	    //make all unreachable values from -1 to large value(1e9)
	    int n = matrix.size();
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            //unreacheable
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e9;
	                
	            //self 
	            if(i == j)  matrix[i][j] == 0;
	        }
	    }
	    
	    //Main logic
	    for(int k = 0; k < n; k++){
	        for(int i = 0; i < n; i++){
	            for(int j = 0; j < n; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    
	    //After
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            //even after compution, if the cell has 1e9 value, it means it is unreacheable
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends