class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        
        vector<int> xorPrefix(n);
        xorPrefix[0] = arr[0];

        for(int i = 1; i < n; i++){
            xorPrefix[i] = arr[i] ^ xorPrefix[i-1];
        }

        for(vector<int> &q: queries){
            int s = q[0];
            int e = q[1];
            int res = 0;

            if(s != 0)
                res = xorPrefix[s-1] ^ xorPrefix[e];
            else
                res = xorPrefix[e];

            ans.push_back(res);
        }

        return ans;
    }
};