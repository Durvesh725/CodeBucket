class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> in;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0; 
        int j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j])
                i++;
            else if(nums2[j] < nums1[i])
                j++;
            else{
                in.insert(nums1[i]);
                i++, j++;
            }
        }

        vector<vector<int>> ans;
        set<int> t;
        for(auto it: nums1){
            if(in.find(it) == in.end()){
                t.insert(it);
            }
        }

        vector<int> temp;
        for(auto it: t)
            temp.push_back(it);
        
        ans.push_back(temp);
        temp.clear();
        t.clear();

        for(auto it: nums2){
            if(in.find(it) == in.end()){
                t.insert(it);
            }
        }

        for(auto it: t)
            temp.push_back(it);
        
        ans.push_back(temp);
        temp.clear();
        t.clear();

        return ans;
    }
};