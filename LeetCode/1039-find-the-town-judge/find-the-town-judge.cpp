class Solution {
public:
    int findJudge(int n, vector<vector<int>>& arr) {
        vector<int> maps(n+1, 0);
        for(auto it: arr){
            maps[it[0]]--;
            maps[it[1]]++;
        }

        for(int i = 1; i <= n; i++){
            if(maps[i] == n-1)
                return i;
        }
        return -1;
    }
};