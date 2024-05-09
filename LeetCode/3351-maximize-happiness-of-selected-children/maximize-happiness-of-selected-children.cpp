class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(), h.rend());
        long long ans = 0;
        int i = 0;
        while(i < h.size()){
            if(k > 0 && h[i] - i >= 0){
                ans += h[i] - i; 
                k--;
            }
            else
                break;
            
            i++;
        }
        return ans;
    }
};
