class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> r(n, 0);
        vector<int> c(m, 0);

        map<int, pair<int, int>> mp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        int sz = arr.size();
        for(int i = 0; i < sz; i++){
            int nrow = mp[arr[i]].first;
            int mcol = mp[arr[i]].second;
            r[nrow]++;
            c[mcol]++;
            if(r[nrow] == m || c[mcol] == n){
                return i;
            }
        }

        return -1;
    }
};