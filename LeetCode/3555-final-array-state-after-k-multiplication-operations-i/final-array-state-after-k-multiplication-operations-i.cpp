class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }

        while(k){
            int num = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            nums[ind] = num * multiplier;
            pq.push({num * multiplier, ind});
            k--;
        }

        return nums;
    }
};