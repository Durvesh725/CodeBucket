class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0);

        for(int &num: arr){
            int rem = (num % k + k) % k;
            mp[rem]++;
        }

        if(mp[0] % 2 != 0)
            return false;

        for(int r = 1; r <= k/2; r++){
            int remain = k - r;
            if(mp[remain] != mp[r]){
                return false;
            }
        }

        return true;
    }
};
