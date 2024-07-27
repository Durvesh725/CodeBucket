class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        long long totalCost = 0;
        vector<vector<int>> shortestPath(26, vector<int>(26, INT_MAX));

        for(int i = 0; i < m; i++){
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            shortestPath[from][to] = min(shortestPath[from][to], cost[i]);
        }

        for(int i = 0; i < 26; i++){
            shortestPath[i][i] = 0;
        }

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(shortestPath[i][k] == INT_MAX || shortestPath[k][j] == INT_MAX)
                        continue;

                    shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][k] + shortestPath[k][j]);
                }
            }
        }

        for(int i = 0; i < n; i++){
            int src = source[i] - 'a';
            int dest = target[i] - 'a';
            if(shortestPath[src][dest] == INT_MAX)
                return -1;
            
            totalCost += shortestPath[src][dest];
        }

        return totalCost;
    }   
};