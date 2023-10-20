//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void dfs(int row, int col, int initColor, vector<vector<int>>& image, vector<vector<int>> &ans, int newColor, int delRow[], int delCol[]){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        //traverse neighbours in 4 directions
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            //check it is safe to change the color
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, initColor, image, ans, newColor, delRow, delCol);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //initial start pixel's color
        int initColor = image[sr][sc];
        //create copy of original image
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, initColor, image, ans, newColor, delRow, delCol);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends