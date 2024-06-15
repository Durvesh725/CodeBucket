class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] == target)  return mid;

            //check for the sorted part
            //1. check left sorted
            if(arr[low] <= arr[mid]){
                if(arr[low] <= target && target <= arr[mid]){
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            else{
                //2. check right sorted
                if(arr[mid] <= target && target <= arr[high]){
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};