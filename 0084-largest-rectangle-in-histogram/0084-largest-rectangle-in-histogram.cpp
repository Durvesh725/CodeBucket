#include<stack>
class Solution {
    private:
    vector<int> nextSmallerElement(vector<int> arr, int n)
    {
       stack<int> st;
       //1. Initially store -1 in stack
       st.push(-1);
         vector<int> ans(n);
       //2. if top element greater than curr, pop the elements from stack till you encounter a smaller one
       for(int i = n-1; i >= 0; i--){
           int curr = arr[i];
           while(st.top() != -1 && arr[st.top()] >= curr){
               st.pop();
           }
           //reached here means top is smaller than curr element
           //save smaller element in vector and push the current ele in stack
           ans[i] = st.top();
           st.push(i);      //***//
       }
       return ans;
    } 
    
    vector<int> prevSmallerElement(vector<int> arr, int n)
    {
       stack<int> st;
       //1. Initially store -1 in stack
       st.push(-1);
        vector<int> ans(n);
       //2. if top element greater than curr, pop the elements from stack till you encounter a smaller one
       for(int i = 0; i < n; i++){
           int curr = arr[i];
           while(st.top() != -1 && arr[st.top()] >= curr){
               st.pop();
           }
           //reached here means top is smaller than curr element
           //save smaller element in vector and push the current ele in stack
           ans[i] = st.top();
           st.push(i);      //***//
       }
       return ans;
    } 
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i = 0; i < n; i++){
            int l = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};