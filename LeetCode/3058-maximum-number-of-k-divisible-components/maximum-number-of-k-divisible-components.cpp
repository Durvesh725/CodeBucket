class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n < 2)
            return 1;
            
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        queue<int> q;
        vector<long long> nodeVal(values.begin(), values.end());

        for(const auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indeg[u]++;
            indeg[v]++;
        }   

        for(int i = 0; i < n; i++){
            if(indeg[i] == 1)
                q.push(i);
        }

        // while(!q.empty()){
        //     cout << q.front() << endl;
        //     q.pop();
        // }

        int cc = 0;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            indeg[currNode]--;

            long long addVal = (nodeVal[currNode] % k == 0) ? 0 : nodeVal[currNode];
            if(addVal == 0)
                cc++;

            for(int neigh: adj[currNode]){
                if(indeg[neigh] > 0)
                    indeg[neigh]--;
                nodeVal[neigh] += addVal;
                if(indeg[neigh] == 1)   
                    q.push(neigh);
            }
        }

        return cc;
    }
};