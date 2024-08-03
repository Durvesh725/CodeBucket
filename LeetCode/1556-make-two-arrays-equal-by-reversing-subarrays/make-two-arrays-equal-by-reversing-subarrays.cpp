class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> um;
        for(int &ele: target){
            um[ele]++;
        }

        for(int &ele: arr){
            if(um[ele] > 0){
                um[ele]--;
            }
        }

        for(auto it: um){
            if(it.second > 0)
                return false;
        }

        return true;
    }
};