//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        // int res = 0;
        // int op = 0;
        // while(res != n){
        //     int doubleN = res * 2;
        //     int add = res + 1;
        //     if(doubleN > add){
        //         res = doubleN;
        //         op++;   
        //     }
        //     else if(add > doubleN){
        //         res = add;
        //         op++;   
        //     }
        //     else{
        //         res = doubleN;
        //         op++;   
        //     }
        // }
        // return op;
        if(n==1)    return 1;
        if(n==2)    return 2;
        int steps = 2;
        while(n>2){
            if(n%2 == 0)    
                n = n/2;
            else
                n = n-1;
            steps++;
        }
        return steps;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends