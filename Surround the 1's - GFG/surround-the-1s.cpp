//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
//function to check all the 8 directions
int count(vector<vector<int> >& matrix, int n, int m, int i, int j){
    int cnt = 0;
    //UP direction
    if(i-1 >=0 && matrix[i-1][j] == 0) cnt++;
    //Down direction
    if(i+1 < n && matrix[i+1][j] == 0) cnt++;
    //right direction
    if(j+1 < m && matrix[i][j+1] == 0) cnt++;
    //left direction
    if(j-1 >= 0 && matrix[i][j-1] == 0) cnt++;
    //left top
    if(i-1 >=0 && j-1 >=0 && matrix[i-1][j-1] == 0) cnt++;
    //right top
    if(i-1 >=0 && j+1 < m && matrix[i-1][j+1] == 0) cnt++;
    //left bottom
    if(i+1 < n && j-1 >= 0 && matrix[i+1][j-1] == 0) cnt++;
    //right bottom
    if(i+1 < n && j+1 < m && matrix[i+1][j+1] == 0) cnt++;
    
    return cnt;
}


public:
    int Count(vector<vector<int> >& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    int cnt = count(matrix, n, m, i, j);
                    if(cnt != 0 && cnt%2 == 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends