class Solution {
public:
    long long findTime(int hour, vector<int> &piles, int n){
        long long time = 0;
        for(int i = 0; i < n; i++){
            time += ceil(piles[i]/(double)hour);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;
        long long ans = LONG_MAX;
        while(low <= high){
            long long mid = (low + high)/2;
            long long totHrs= findTime(mid, piles, n);

            if(totHrs <= h){
                // ans = min(ans, mid);
                high = mid - 1;
            }
            else
            // if(totHrs >= h)
                low = mid + 1;
        }
        return low;
    }
};