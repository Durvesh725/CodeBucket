class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int c1 = 1, c2 = 1;
        int mc1 = INT_MIN, mc2 = INT_MIN;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i-1]){
                c1++;
                mc1 = max(mc1, c1);
            } 
            else    c1 = 1;
        }  

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < arr[i-1]){
                c2++;
                mc2 = max(mc2, c2);
            }   
            else    c2 = 1;
        }   
        if(mc1 == INT_MIN && mc2 == INT_MIN)
            return max(c1, c2);

        return max(mc1, mc2);
    }
};