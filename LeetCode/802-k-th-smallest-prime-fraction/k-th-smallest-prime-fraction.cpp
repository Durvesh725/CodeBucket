class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int, int>>> f;
        int n = arr.size();
        double res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                res = double(arr[i]) / arr[j];
                f.push_back({res, {arr[i], arr[j]}});
            }
        }

        sort(f.begin(), f.end());

        int no1 = f[k-1].second.first;
        int no2 = f[k-1].second.second;  

        return {no1, no2};      
    }
};