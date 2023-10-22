//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        //Initialize parent array
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    //method to find parent: whenever this method is called, the path compression takes place
    int findUPar(int node){
        if(node == parent[node])
            return node;
        //path compression
        return parent[node] = findUPar(parent[node]);
    }
    
    //UNION BY size
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)  return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        //if sizes are equal
        else{
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //Using kruskal's algo
        //store: {w, {u, v}}} 
        vector<pair<int, pair<int, int>>> edges;
        //therefore
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                int node = i;
                int adjNode = it[0];
                int weight = it[1];
                edges.push_back({weight, {node, adjNode}});
            }
        }
        
        //2. sort them in increasing order of thier weight
        sort(edges.begin(), edges.end());
        
        //3
        DisjointSet ds(V);
        int mstWeight = 0;
        for(auto it: edges){
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWeight += w;
                ds.unionBySize(u, v);
            }
        }
        return mstWeight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends