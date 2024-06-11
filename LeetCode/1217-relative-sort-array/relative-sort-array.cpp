class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int, int> mp;
        int n = arr1.size();
        for(int i = 0; i < n; i++){
            mp[arr1[i]]++;
        }

        int m = arr2.size();
        for(int i = 0; i < m; i++){
            while(mp[arr2[i]] != 0){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        for(auto it: mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
            else{
                while(it.second != 0){
                    ans.push_back(it.first);
                    it.second--;
                }
            }
        }

        return ans;
    }
};