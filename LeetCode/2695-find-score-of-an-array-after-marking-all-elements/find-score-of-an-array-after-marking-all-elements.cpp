class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }

        long long sum = 0;
        while(!pq.empty()){
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            if(nums[ind] != -1){
                sum += nums[ind];
                nums[ind] = -1;
                if(ind-1 >= 0 && nums[ind-1] != -1){
                    nums[ind-1] = -1;
                }

                if(ind+1 < nums.size() && nums[ind+1] != -1){
                    nums[ind+1] = -1;
                }
            }
        }
        return sum;
    }
};