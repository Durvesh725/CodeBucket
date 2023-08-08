//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        //1. put all persons in stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        //2. while stack is != 1, pop two ele
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(M, a, b, n)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int candidate = st.top();
        
        //3. Verify the candidate
        //3.1 check if he KNOWS ANYONE
        int knowsCount = 0;
        for(int i = 0; i < n; i++){
            if(M[candidate][i] == 0){
                knowsCount++;
            }
        }
        
        if(knowsCount != n)
            return -1;
        
        
        //3.2 check if ANYONE KNOWS him
        int anyoneKnows = 0;
        for(int i = 0; i < n; i++){
            if(M[i][candidate] == 1){
                anyoneKnows++;
            }
        }
        
        if(anyoneKnows != n-1)
            return -1;
            
        return candidate;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends