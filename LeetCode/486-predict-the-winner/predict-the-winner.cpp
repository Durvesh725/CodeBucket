class Solution {
private:
    int solve(int i, int j, vector<int> &nums){
        if(i > j)   return 0;

        if(i == j)  return nums[j];

        //2 choices: consider only player 1 moves: (Hidden layer of P2 player playing is considered and as he play
        //optimally, therefore, directly what player 1 will get to choose next is considered(he will get worst because  they play optimally))
        int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1, j-1, nums));
        int take_j = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));

        return max(take_i, take_j);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int total_s = accumulate(nums.begin(), nums.end(), 0);
        int p1_s = solve(0, n-1, nums);
        int p2_s = total_s - p1_s;

        return p1_s >= p2_s;
    }
};