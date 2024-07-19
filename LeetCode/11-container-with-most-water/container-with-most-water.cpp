class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int i = 0;
        int j = n-1;
        while(i < j){
            int w = j - i;
            int h = min(height[i], height[j]);
            int area = w * h;
            maxArea = max(maxArea, area);
            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
            // i++;
        }
        return maxArea;
    }
};

//2,3,4,5,18,17,6