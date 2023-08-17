//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int> newQ;
        int mid = q.size()/2;
        for(int i = 0; i < mid; i++){
            newQ.push(q.front());
            q.pop();
        }
        while(!newQ.empty()){
            q.push(newQ.front());
            q.push(q.front());
            newQ.pop();
            q.pop();
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends