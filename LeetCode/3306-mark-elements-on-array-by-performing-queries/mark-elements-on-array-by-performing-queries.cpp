class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            pq.push({nums[i], i});
        }

        // while (!pq.empty()) {
        //     pair<int, int> topPair = pq.top();
        //     cout << "(" << topPair.first << ", " << topPair.second << ") ";
        //     pq.pop();
        // }

        vector<long long> ans;
        for(auto it: queries){
            sum -= nums[it[0]];
            nums[it[0]] = 0;
            int markk = it[1];
            while(pq.size() && markk){
                if(nums[pq.top().second]){
                    sum -= nums[pq.top().second];
                    nums[pq.top().second] = 0;
                    markk--;
                }
                pq.pop();
            }
            ans.push_back(sum);
        }
        return ans;
    }
};