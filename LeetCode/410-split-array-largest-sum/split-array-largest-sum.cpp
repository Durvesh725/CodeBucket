class Solution {
public:
    int cntStudent(int pages, vector<int> & arr){
        int n = arr.size();
        int maxPages = 0, student = 1;
        for(int i = 0; i < n; i++){
            if(maxPages + arr[i] <= pages){
                maxPages += arr[i];
            }
            else{
                student++;
                maxPages = arr[i];
            }
        }
        return student;
    }

    int splitArray(vector<int>& arr, int m) {
        int n = arr.size();
        if(m > n)
        return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low <= high){
            int mid = (low+high)/2;
            int cntS = cntStudent(mid, arr);
            //less students means I need to decrease the number of pages
            if(cntS > m)
                low = mid + 1;
            else    
                high = mid - 1;
        }

        return low;   
    }
};