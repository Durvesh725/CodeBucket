//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(vector<int> &vis, vector<int>adj[], int node, set<int> &s){
        vis[node] = 1;
        s.insert(node);
        //check for the particular nodes adjacency list
        for(auto it: adj[node]){
            if(s.find(it) == s.end())
                dfs(vis, adj, it, s);
        }
    }
    
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> vis(V, 0);
	    //traverse across all nodes
	    for(int i = 0; i < V; i++){
	        set<int> s;
	        if(!vis[i]){
	            dfs(vis, adj, i, s);
	        if(s.size() == V)
	            return i;
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends