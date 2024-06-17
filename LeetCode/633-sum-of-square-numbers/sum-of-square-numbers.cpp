class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a = 0; a*a <= c; a++){
            long x = c - a*a;
            int low = 0, high = x;
            while(low <= high){
                long mid = (low+high)/2;
                if(mid*mid == x)
                    return true;
                else if(mid*mid > x)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};