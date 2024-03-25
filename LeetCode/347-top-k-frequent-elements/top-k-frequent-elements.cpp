class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++)
            um[nums[i]]++;

        priority_queue<pair<int, int>> pq;
        for(auto it: um){
            pq.push({it.second, it.first});
        }

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};