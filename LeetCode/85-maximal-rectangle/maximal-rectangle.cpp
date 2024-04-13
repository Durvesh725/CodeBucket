class Solution {
private:
    vector<int> getNSL(vector<int> &arr, int &n){
        vector<int> res(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) {st.pop();}
            res[i] = (st.empty()) ? 0 : st.top()+1;
            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int> &arr, int &n){
        vector<int> res(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) {st.pop();}
            res[i] = (st.empty()) ? n-1 : st.top()-1;
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL = getNSL(heights, n);
        vector<int> NSR = getNSR(heights, n);  

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, (NSR[i] - NSL[i] + 1) * heights[i]);
        }    
        
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxA = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxA = max(maxA, largestRectangleArea(heights));
        }
        return maxA;
    }
};