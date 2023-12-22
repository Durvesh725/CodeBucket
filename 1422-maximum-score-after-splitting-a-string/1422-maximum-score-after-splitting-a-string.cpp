class Solution {
public:
    int maxScore(string s) {
        //intution: at each iteration, we can count the no of zeros on the left hand side and no. of ones on the right hand side
        //for that, precompute the no of ones and go on decrementing the count as you move further (i.e go on splitting)
        
        int max_score = 0;
        int count_zeros_left = 0;
        int count_ones_right = count(s.begin(), s.end(), '1');

        for (int i = 0; i < s.size() - 1; ++i) {
            count_zeros_left += (s[i] == '0');
            count_ones_right -= (s[i] == '1');
            max_score = max(max_score, count_zeros_left + count_ones_right);
        }

        return max_score;
    }
};