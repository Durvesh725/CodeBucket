class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ps = 0;
        unordered_map <int, int> firstOcc;
        firstOcc[0] = 0;

        for(int i = 0; i < n; i++){
            ps = (ps + nums[i]) % k;
            if(firstOcc.find(ps) != firstOcc.end()){
                if(i+1 - firstOcc[ps] >= 2) 
                    return true;
            }
            else{
                firstOcc[ps] = i+1;
            }
        }

        return false;
    }
};

//firstOcc of ps % k
//pb - pa = range
//range % k = 0;
//i.e pb % k - pa % k = 0;
//pb % k = pa % k