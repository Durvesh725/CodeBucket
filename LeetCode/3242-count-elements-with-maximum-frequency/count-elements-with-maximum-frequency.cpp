class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int cnt = 0;
        int maxF = 0;
        for(auto x: nums){
            freq[x]++;
            cnt += (freq[x] == maxF);

            if(freq[x] > maxF){
                cnt = 1;
                maxF = freq[x];
            }
        }
        return cnt*maxF;
    }
};