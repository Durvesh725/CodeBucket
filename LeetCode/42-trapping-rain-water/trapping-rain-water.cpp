class Solution {
public:
    int trap(vector<int>& height) {
        //water trapped: left max, right max, subtract current elements from the min of both
        int n = height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = height[0];
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }

        suffix[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }

        int waterTrapped = 0;
        for(int i = 0; i < n; i++){
            waterTrapped += min(prefix[i], suffix[i]) - height[i];
        }

        return waterTrapped;
    }
};