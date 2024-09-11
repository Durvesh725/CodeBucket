class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorRes = start ^ goal;
        int count = 0;

        while(xorRes != 0){
            count += (xorRes & 1);
            xorRes = xorRes >> 1;
        }

        return count;
    }
};