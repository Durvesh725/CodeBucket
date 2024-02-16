class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        for(int i = 0; i < arr.size(); i++){
            um[arr[i]]++;
        }

        vector<int> freq;
        for(auto it: um){
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end());
        int ans = 0;
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] <= k){
                k -= freq[i];
                ans++;
            }
            else
                break;
        }
        return freq.size()-ans;
    }
};