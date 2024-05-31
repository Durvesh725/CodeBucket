class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor = 0;
        for (int num : nums) {
            all_xor ^= num;
        }  

        unsigned int lowestBit = all_xor & -(unsigned int)all_xor;

        vector<int> res(2, 0);
        for (int num : nums) {
            if ((lowestBit & num) == 0) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }

        return res;
    }
};