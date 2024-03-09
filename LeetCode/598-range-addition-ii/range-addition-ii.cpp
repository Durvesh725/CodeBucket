class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0){
            return m*n;
        }

        int initm = ops[0][0];
        int initn = ops[0][1];

        for(auto it: ops){
            if(it[0] < initm)
                initm = it[0];
            if(it[1] < initn)
                initn = it[1];
        }

        return initm * initn;
    }
};