class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int i = 0, cnt = 0;
        while(i < n){
            if(arr[i]&1){
                cnt++;
            }
            else{
                if(cnt >= 3)
                    return true; 
                cnt = 0;
            }
            i++;
        }
        return (cnt >= 3) ? true: false;
    }
};