class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int bitsunion = 0;
        int res = 0;

        while(j < n){
            int element = nums[j];
            while((bitsunion & element) != 0){
                bitsunion ^= nums[i];
                i++;
            }
            bitsunion = bitsunion | element;
            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};

// A B C
// A & B & C == 0
//if new element d comes -> its AND with all of A,B,C should comes zero
//instead of taking and with everyone, (A | B | C) & D == 0