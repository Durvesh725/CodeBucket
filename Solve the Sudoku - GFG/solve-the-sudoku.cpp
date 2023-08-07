//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    private:
    bool isSafe(int row, int col, int grid[N][N], int val){
        for(int i = 0; i < 9.; i++){
            //if test val == any value in particular col found
            if(grid[row][i] == val)
                return false;
            if(grid[i][col] == val)
                return false;
            if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return false;
        }
        return true;
    }
    
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        //get no.of rows & cols
        int n = 9;
        //traverese the matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //now check if there exists any empty space
                if(grid[i][j] == 0){
                    //now test values between 1 - 9
                    for(int val = 1; val <= 9; val++){
                        //check if the value for test is safe to insert
                        if(isSafe(i, j, grid, val)){
                            grid[i][j] = val;
                            bool findNextSol = SolveSudoku(grid);   
                            if(findNextSol)
                                return true;
                            else
                                //backtrack
                                grid[i][j] = 0;
                        }
                    }
                    //if all values are tested and none of them satisfy
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        SolveSudoku(grid);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends