//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
    vector<int> nextSmallerElement(int *arr, int n)
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
    
    vector<int> prevSmallerElement(int *arr, int n)
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
    
    int largestRectangleArea(int *heights, int n) {
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
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        //1. Firstly, compute first row area
        int area = largestRectangleArea(M[0], m);
        
        //2. traverse for all remaining rows
        //   update value of each row by adding elements from prev row
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                //as it is next row, if bottom element is zero, histogram cannot be constructed
                if(M[i][j] != 0){
                    //colwise addition for particular ith row(ref. outer for loop)
                    M[i][j] = M[i][j] + M[i-1][j];   
                }
                else
                    M[i][j] = 0;
            }
            //3. Now compute max (lastest calculated row is passed each time)
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends