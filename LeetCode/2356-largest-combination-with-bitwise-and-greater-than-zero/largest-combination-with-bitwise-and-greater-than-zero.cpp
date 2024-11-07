class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCnt = 0;
        
        for(int bit = 0; bit < 32; bit++){
            int cntBit = 0;
            for(int &num: candidates){
                if(num & (1 << bit)){
                    cntBit++;
                }
            }
            maxCnt = max(maxCnt, cntBit);
        }
        return maxCnt;
    }
};