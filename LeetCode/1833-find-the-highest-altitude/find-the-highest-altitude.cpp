class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = 0;
        int al = 0;

        for(int i = 0; i < n; i++){
            al += gain[i];
            maxi = max(maxi, al);
        }

        return maxi;
    }
};