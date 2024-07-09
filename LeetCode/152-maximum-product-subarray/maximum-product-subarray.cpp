class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double prod_left = 1;
        double prod_right = 1;
        double max_prod = INT_MIN;

        for(int i = 0; i < n; i++){
            prod_left *= nums[i];
            prod_right *= nums[n-i-1];

            max_prod = max({max_prod, prod_left, prod_right});

            if(prod_left == 0)
                prod_left = 1;

            if(prod_right == 0)
                prod_right = 1;
        }
        
        return max_prod;
    }
};