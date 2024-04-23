class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};

        //create adj list and also maintain the indeg
        vector<vector<int>> adj(n);
        vector<int> indeg(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indeg[edge[0]]++;
            indeg[edge[1]]++;
        }
    
        //push nodes with indegree 1 into the queue
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 1)
                q.push(i);
        }

        while(n > 2){
            int size = q.size();
            n -= size;

            while(size--){
                int node = q.front();
                q.pop();

                for(auto it: adj[node]){
                    indeg[it]--;
                    if(indeg[it] == 1)
                        q.push(it);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};