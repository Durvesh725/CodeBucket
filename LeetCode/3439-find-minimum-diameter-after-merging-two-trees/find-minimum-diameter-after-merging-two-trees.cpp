class Solution {
public:
    vector<vector<int>> makeGraph(vector<vector<int>> &edges){
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    void findExtreme(int curr, int parent, int distance, vector<vector<int>> &adj, pair<int, int> &res){
        if(distance > res.first)
            res = {distance, curr};

        for(auto neighbour: adj[curr]){
            if(neighbour != parent)
                findExtreme(neighbour, curr, distance+1, adj, res);
        }
    }



    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto g1 = makeGraph(edges1), g2 = makeGraph(edges2);

        pair<int, int> res1 = {INT_MIN, -1}, res2 = {INT_MIN, -1};

        findExtreme(0, -1, 0, g1, res1);
        findExtreme(res1.second, -1, 0, g1, res2);
        int tree1Diameter = res2.first;

        res1 = {INT_MIN, -1}, res2 = {INT_MIN, -1};
        findExtreme(0, -1, 0, g2, res1);
        findExtreme(res1.second, -1, 0, g2, res2);
        int tree2Diameter = res2.first;

        int mergeDiameter = (tree1Diameter+1)/2 + (tree2Diameter+1)/2 + 1;
        return max({tree1Diameter, tree2Diameter, mergeDiameter});
    }
};

//upsolved
//to find diameter in graph: 
//1. perform dfs from any node to find extreme node
//2. perform dfs from that extreme node to its extreme node, this will give you the diameter