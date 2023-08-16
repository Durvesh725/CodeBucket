//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //vector to store ans
        if(n==1 || n==0) return 1;
        int mod = 1e9+7;
        vector<long long int> ans(n+1, 0);
        ans[0] = 1;
        ans[1] = 1;
        //outer loop to maintain the range
        for(int i = 2; i <= n; i++){
            //Eg: C2 = C0*C1 + C1*C0 
            //inner while loop helps to satisfy the above formula
            int l = 0, r = i - 1;
            while(l < i && r >= 0){
                ans[i] = (ans[i] + (ans[l] * ans[r])%mod)%mod;
                l++;
                r--;
            }
        }
        return ans[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends