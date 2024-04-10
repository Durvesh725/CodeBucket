class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

    long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left_ele = i - NSL[i];
            long long right_ele = NSR[i] - i;

            long long totalWays = left_ele * right_ele;

            long long totalSum = arr[i] * totalWays;

            sum = (sum + totalSum);
        }
        return sum;
    }

    long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNGL(arr, n);
        vector<int> NSR = getNGR(arr, n);

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left_ele = i - NSL[i];
            long long right_ele = NSR[i] - i;

            long long totalWays = left_ele * right_ele;

            long long totalSum = arr[i] * totalWays;

            sum = (sum + totalSum);
        }
        return sum;
    }

    //sum of subarray minimums 
    vector<int> getNSL(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(st.empty())
                res[i] = -1;
            else{
                // >= to handle duplicates(edge case) (2,6,2,4,2)
                while(!st.empty() && arr[st.top()] >= arr[i])
                    st.pop();

                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> getNSR(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty())
                res[i] = n;
            else{
                // >= to handle duplicates(edge case) (2,6,2,4,2)
                while(!st.empty() && arr[st.top()] > arr[i])
                    st.pop();
                    
                res[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return res;
    }

    //sum of subarray maximums
    vector<int> getNGL(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(st.empty())
                res[i] = -1;
            else{
                // <= to handle duplicates(edge case) (2,6,2,4,2)
                while(!st.empty() && arr[st.top()] <= arr[i])
                    st.pop();

                res[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return res;
    }

    vector<int> getNGR(vector<int>& arr, int n){
        vector<int> res(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty())
                res[i] = n;
            else{
                // <= to handle duplicates(edge case) (2,6,2,4,2)
                while(!st.empty() && arr[st.top()] < arr[i])
                    st.pop();
                    
                res[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return res;
    }
};