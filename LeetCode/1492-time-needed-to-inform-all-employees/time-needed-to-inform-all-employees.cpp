class Solution {
public:
    int maxTime = 0;
    void dfs(int curr_headID, unordered_map<int, vector<int>> &um, vector<int>& informTime, int time){
        maxTime = max(maxTime, time);
        for(auto &employee: um[curr_headID]){
            dfs(employee, um, informTime, time + informTime[curr_headID]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> um;
        for(int i = 0; i < n; i++){
            if(manager[i] != -1)
                um[manager[i]].push_back(i);
        }

        dfs(headID, um, informTime, 0);

        return maxTime;
    }
};