class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int ans=0;

        int last = 1e5;
        int prof = 0;
        
        for(int i = 0; i<n; i++){
            if(prices[i] < last){
                last = prices[i];
            }
            prof = prices[i] - last;
            ans=max(prof,ans);
           
        }
        return ans;
        
    }
};