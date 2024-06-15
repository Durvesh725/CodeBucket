class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int h = n-1;
        int ans = INT_MAX;
        while(l <= h){
            int mid = (l+h)/2;
            //check if left part sorted, if yes min ele obv is arr[l];
            if(arr[l] <= arr[mid]){
                ans = min(ans, arr[l]);
                l = mid + 1;
            }
            else{
                //right part is sorted, min ele will be arr[mid];
                ans = min(ans, arr[mid]);
                h = mid - 1;
            }
        }
        return ans;
    }
};