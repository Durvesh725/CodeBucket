class Solution {
private:
    bool dfs(vector<vector<int>> &adj, int src, int &dest, vector<int> &vis){
        if(src == dest)
            return true;

        vis[src] = 1;

        for(auto &node: adj[src]){
            if(!vis[node]){
                if(dfs(adj, node, dest, vis))
                    return true;
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(n, 0);
        return dfs(adj, source, destination, vis);
    }
};