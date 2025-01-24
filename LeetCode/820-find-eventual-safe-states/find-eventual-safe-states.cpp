class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> od(n);
        vector<vector<int>> pred(n);

        for(int i = 0; i < n; i++){
            for(int out: graph[i]){
                od[i]++;
                pred[out].push_back(i);
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(od[i] == 0)
                q.push(i);
        }

        vector<bool> isSafe(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            isSafe[node] = true;

            for(int neigh: pred[node]){
                od[neigh]--;
                if(od[neigh] == 0)  q.push(neigh);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(isSafe[i])
                ans.push_back(i);
        }

        // sort(ans.begin(), ans.end());

        return ans;
    }
};