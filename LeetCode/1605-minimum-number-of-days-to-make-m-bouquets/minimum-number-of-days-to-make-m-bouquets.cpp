class Solution {
public:
    bool canFormBouquet(int &min_days, vector<int>& bloomDay, int m, int k){
        int n = bloomDay.size();
        int cnt = 0, i = 0, bouquet = 0;
        while(i < n){
            if(bloomDay[i] <= min_days){
                cnt++;
                i++;
            }
            else{
                bouquet += (cnt / k);
                cnt = 0;
                i++;
            }
        }

        if(bouquet == 0 || cnt)
            bouquet += cnt / k;

        if(bouquet >= m)
            return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long form = (long)m * k;
        if(form > bloomDay.size())
            return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int low = mini;
        int high = maxi;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            bool possible = canFormBouquet(mid, bloomDay, m, k);
            if(possible){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};