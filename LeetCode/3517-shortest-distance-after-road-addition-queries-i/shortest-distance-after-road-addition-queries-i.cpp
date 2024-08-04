class Solution {
public:
    int dijkstra(int V, vector<vector<pair<int, int>>> &adj){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> d(V, INT_MAX);
        d[0] = 0;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjDist = it.second;
                int adjNode = it.first;
                
                if(dist + adjDist < d[adjNode]){
                    d[adjNode] = dist + adjDist;
                    pq.push({d[adjNode], adjNode});
                }
            }
        }
        
        return d[V-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n);
        vector<int> ans;
        for(int i = 0; i < n-1; i++){
            graph[i].push_back({i+1, 1});
        }

        for(auto &it: queries){
            graph[it[0]].push_back({it[1], 1});
            ans.push_back(dijkstra(n, graph));
        }

        return ans;
    }
};