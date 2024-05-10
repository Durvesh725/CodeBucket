class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> f;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                f.push_back({arr[i], arr[j]});
            }
        }

        vector<pair<double, pair<int, int>>> ans;
        for(int i = 0; i < f.size(); i++){
            double res = double(f[i].first) / f[i].second;
            ans.push_back({res, {f[i].first, f[i].second}});
        }

        sort(ans.begin(), ans.end());

        int no1 = ans[k-1].second.first;
        int no2 = ans[k-1].second.second;  

        return {no1, no2};      
    }
};