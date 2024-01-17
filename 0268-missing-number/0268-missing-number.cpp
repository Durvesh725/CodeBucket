class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+1, 0);
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        
        for(int i = 0; i <=n; i++){
            if(arr[i] == 0){
                return i;
            }
        }
        
        return -1;
        
        //OPTIMAL
        // int n = nums.size();
        // //formula for finding sum of n natural nos
        // int Sn = (n*(n+1))/2;
        // int S = 0;
        // for(int i=0; i<n; i++){
        //     S+=nums[i];
        // }
        // return Sn - S;
    }
};