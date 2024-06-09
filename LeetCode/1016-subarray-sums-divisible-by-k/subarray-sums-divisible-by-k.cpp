class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainder;
        remainder[0] = 1;
        //if 0 is seen next time we want its previous count to be added therefore init 1

        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int r = sum % k;

            if(r < 0)
                r += k;

            //to keep the track of previously seen subarray with the help of remainder
            if(remainder.find(r) != remainder.end())
                ans += remainder[r];

            remainder[r]++;
        }

        return ans;
    }
};

//intuition:
//S: SUM
//s1-s2 - what lefts while be divisible by k provided if s1%k == s2%k
//      S2
//      ---------
//Nums: 2 3 5 4 5 3 4
//R   : 2 5 3 0 5 1 5
//      ---
//      S1
//          5 4 5 (is one subarray divisible by 7

//when r is neg: do +k