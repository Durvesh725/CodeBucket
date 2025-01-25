class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> map;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            map.push_back({nums[i], i});
        }
        sort(map.begin(), map.end());

        vector<vector<int>> group = {{map[0].second}};
        for(int i = 1; i < n; i++){
            if(map[i].first - map[i-1].first <= limit){
                group.back().push_back(map[i].second);
            }
            else{
                group.push_back({map[i].second});
            }
        }

        for(vector<int> &grp: group){
            vector<int> vals;
            for(int &ind: grp)
                vals.push_back(nums[ind]);

            sort(grp.begin(), grp.end());

            for(int i = 0; i < grp.size(); i++){
                nums[grp[i]] = vals[i];
            }
        }

        return nums;
    }
};

// upsolved