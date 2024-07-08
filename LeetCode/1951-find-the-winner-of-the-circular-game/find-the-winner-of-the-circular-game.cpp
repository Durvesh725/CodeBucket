class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> circle(n);
        iota(circle.begin(), circle.end(), 1);
        int curr_pos = 0;

        while(n > 1){
            curr_pos = (curr_pos + k - 1) % n;
            circle.erase(circle.begin() + curr_pos);
            n--;
        }

        return circle[0];
    }
};