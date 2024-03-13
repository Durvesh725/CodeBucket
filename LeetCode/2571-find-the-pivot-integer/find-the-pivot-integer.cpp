class Solution {
public:
    int pivotInteger(int n) {
        int nsum = n*(n+1)/2;
        int sum = 0;
        for(int i = n; i >= 1; --i){
            sum += i;
            if((nsum - sum + i) == sum)
                return i;
        }
        return -1;
    }
};