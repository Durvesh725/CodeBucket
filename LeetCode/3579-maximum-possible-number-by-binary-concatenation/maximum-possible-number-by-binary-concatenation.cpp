class Solution {
public:
    string toBinary(int num){
        return bitset<8> (num).to_string().substr(bitset<8> (num).to_string().find('1'));
    }

    int maxGoodNumber(vector<int>& nums) {
        string add = "";
        int maxi = INT_MIN;
        sort(nums.begin(), nums.end());

        do{
            add = toBinary(nums[0]) + toBinary(nums[1]) + toBinary(nums[2]);
            maxi = max(maxi, stoi(add, 0, 2));
        }while(next_permutation(nums.begin(), nums.end()));

        return maxi;
    }
};