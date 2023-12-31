//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    int mod = 1e9+7;
    //10 raise to 9
    
    int findFib(int n, vector<int> &dp){
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        //if solution for the subproblem already exists, return that value directly
        if(dp[n] != -1)
            return dp[n];
            
        //else store that value in the dp
        return dp[n] = (findFib(n-1, dp) + findFib(n-2, dp)) % mod;
    }
    
  public:
    int nthFibonacci(int n){
        //initialize 1D DP array
        vector<int> dp(n+1, -1);
        return findFib(n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends