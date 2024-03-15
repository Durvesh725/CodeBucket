class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int> ans;
        // int l = 0;
        // int r = nums.size()-1;
        // int s1 = 1;
        // int s2 = 1;
        // int i = 0;
        // while(i < nums.size()){
        //     while(l < i || r > i){
        //         if(l < i) s1 *= nums[l++];
        //         if(r > i) s2 *= nums[r--];
        //     }
        //     ans.push_back(s1 * s2);
        //     i++;
        //     l = 0, r = nums.size()-1;
        //     s1 = 1, s2 = 1;
        // }   
        // return ans;

        int n = nums.size();
        vector<int> ans(n, 1);

        // Calculate the product of all the numbers to the left of each number
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= left_product;
            left_product *= nums[i];
        }

        // Calculate the product of all the numbers to the right of each number
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }

        return ans;
    }
};

// 