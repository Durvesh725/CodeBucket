class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> prime;
        for(int i = 0; i < nums.size(); i++){
            bool f = 1;
            for(int k = 2; k <= sqrt(nums[i]); k++){
                if(nums[i] % k == 0){
                    f = 0;
                    break;
                }
            }

            if(f && nums[i] > 1)
                prime.push_back(i);
        }

        sort(prime.begin(), prime.end());
        return prime[prime.size()-1] - prime[0];
    }
};

//0 1 2 3 4
//4 2 9 5 3

//2, 5, 3