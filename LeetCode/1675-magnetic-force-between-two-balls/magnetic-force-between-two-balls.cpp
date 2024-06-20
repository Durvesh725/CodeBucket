class Solution {
public:
    bool canWePlace(int min_dist, vector<int>& position, int m){
        int n = position.size();
        int lastPlaced = position[0], balls = 1;
        for(int i = 1; i < n; i++){
            if(position[i] - lastPlaced >= min_dist){
                balls++;
                lastPlaced = position[i];
            }
            if(balls >= m)
                return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int mini = position[0];
        int maxi = position[n-1] ;
        int limit = maxi - mini;
        // for(int i = 1; i <= 6; i++){
        //     if(canWePlace(i, position, m) == false){
        //         return i - 1;
        //     }
        // }
        int low = 1;
        int high = maxi - mini;
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            bool possible = canWePlace(mid, position, m);
            if(possible){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};