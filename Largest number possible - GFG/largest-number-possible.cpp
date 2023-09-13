//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans = "";
        for(int i = 0; i < N; i++){
            if(S>=9){
                ans = ans+'9';
                S = S - 9;
            }
            else{
                ans = ans + to_string(S); 
                S = S - S;
            }
        }
        if((N>1) && ans[0] == '0')
            return "-1";
        if(S == 0)
            return ans;
        
        return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends