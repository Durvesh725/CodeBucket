class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while(right < n){
            maxHeap.push({nums[right], right});
            minHeap.push({nums[right], right});
            if(maxHeap.top().first - minHeap.top().first <= limit){
                maxLen = max(maxLen, right - left + 1);
            }
            else{
                int minInd = min(maxHeap.top().second, minHeap.top().second);
                left = minInd + 1;
                if(minInd == maxHeap.top().second){
                    while(!(maxHeap.empty()) && (maxHeap.top().second < left)){
                        maxHeap.pop();
                    }
                }
                else{
                    while(!(minHeap.empty()) && (minHeap.top().second < left)){
                        minHeap.pop();
                    }
                }
            }
            right++;
        }  

        return maxLen;       
    }
};

//1. 2,1,4,4,3,10 limit: 6 
//2. 10, 1, 2, 4, 7, 2 limit: 5