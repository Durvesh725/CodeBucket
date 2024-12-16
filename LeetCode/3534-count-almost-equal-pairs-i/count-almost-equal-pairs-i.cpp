class Solution {
public:
    bool check(int n1, int n2){
        vector<pair<int, int>> temp;
        while(n1 > 0 || n2 > 0){
            int d1 = n1 % 10;
            int d2 = n2 % 10;
            if(n1!=0) n1 /= 10;
            if(n2!=0) n2 /= 10;
            if(d1 != d2){
                temp.push_back({d1, d2});
                if(temp.size() > 2)
                    return false;
            }
        }

        if(temp.size() == 1 || temp.size() > 2)
            return false;
        if(temp.size() == 0)
            return true;
        if((temp[0].first == temp[1].second) && (temp[1].first == temp[0].second))
            return true;
        
        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(check(nums[i], nums[j]))
                    cnt++;
            }
        }

        return cnt;
    }
};