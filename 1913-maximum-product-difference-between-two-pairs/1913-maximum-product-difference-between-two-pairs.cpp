class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0, secondBig = 0, small = INT_MAX, secondSmall = INT_MAX;
        
        for(int num: nums){
            secondBig = (num > biggest) ? exchange(biggest, num) : max(secondBig, num);
            secondSmall = (num < small) ? exchange(small, num) : min(secondSmall, num);
        }
        
        return (biggest * secondBig) - (small * secondSmall);
    }
};