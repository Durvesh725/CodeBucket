class Solution {
public:
    void performBFS(int &start,  vector<vector<int>> &adj, vector<vector<int>> &edge){
        queue<int> q;
        q.push(start);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(!edge[start][it]){
                    edge[start][it] = 1;
                    q.push(it);
                }
            }
        }   
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        int sz = prerequisites.size();
        for (auto &prereq : prerequisites) {
            adj[prereq[0]].push_back(prereq[1]);
        }

        vector<vector<int>> edge(numCourses, vector<int>(numCourses, 0));
        for(int i = 0; i < numCourses; i++){
            performBFS(i, adj, edge);
        }

        vector<bool> ans;
        int n = queries.size();
        for(int i = 0; i < n; i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(edge[u][v] == 1){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};