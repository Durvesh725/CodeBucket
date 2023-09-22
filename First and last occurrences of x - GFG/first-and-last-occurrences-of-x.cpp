//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans;
        int i = 0;
        while(arr[i] != x && i < n){
            i++;
        }
        
        if(arr[i] == x){
            int first = i;
            ans.push_back(first);   
        }else{
            ans.push_back(-1);
        }
        
        int k = i;
        
        while(arr[k] == x){
            // if(arr[k] == x){
                k++;
            // }
        }
        
        if(arr[k-1] == x){
            int second = k-1;
            ans.push_back(second);  
        }else{
            ans.push_back(-1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends