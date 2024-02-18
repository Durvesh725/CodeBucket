class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        vector<int> tempInterval = intervals[0];
        for(auto it: intervals){
            //check if overlapping
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(it[1], tempInterval[1]);
            }
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }    
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;  
    }
};