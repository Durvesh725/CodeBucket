class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
     
        int ans, diff = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(j-1 < 0) continue;
                int a = *lower_bound(nums.begin(), nums.begin()+j-1, target-nums[i]-nums[j]-1);
                int b = *upper_bound(nums.begin(), nums.begin()+j-1, target-nums[i]-nums[j]-1);
                int c = *lower_bound(nums.begin(), nums.begin()+j-1, target-nums[i]-nums[j]);
                int d = *upper_bound(nums.begin(), nums.begin()+j-1, target-nums[i]-nums[j]);
                
                if(abs(a+nums[i]+nums[j]-target) < diff){
                    diff = abs(a+nums[i]+nums[j]-target);
                    ans = a+nums[i]+nums[j];
                }
                if(abs(b+nums[i]+nums[j]-target) < diff){
                    diff = abs(b+nums[i]+nums[j]-target);
                    ans = b+nums[i]+nums[j];
                }
                if(abs(c+nums[i]+nums[j]-target) < diff){
                    diff = abs(c+nums[i]+nums[j]-target);
                    ans = c+nums[i]+nums[j];
                }
                if(abs(d+nums[i]+nums[j]-target) < diff){
                    diff = abs(d+nums[i]+nums[j]-target);
                    ans = d+nums[i]+nums[j];
                }
            }
        }
        
        return ans;
    }
};
