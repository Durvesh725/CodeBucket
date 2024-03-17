class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums){
        int sum = 0;
        for(auto x: nums){
            int maxi = 0, temp = 0, cnt = 0;
            while(x){
                maxi = max(maxi, x%10);
                x = x / 10;
                cnt++;
            }

            while(cnt){
                temp = temp * 10 + maxi;
                cnt--;
            }

            sum += temp;
        }
        return sum;
    }
};