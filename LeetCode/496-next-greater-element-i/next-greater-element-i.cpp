class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        stack<int> st;
        int n2 = nums2.size();
        
        for(int i = 0; i < n2; i++){
            while(!st.empty() && st.top() < nums2[i]){
                um[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        int n1 = nums1.size();
        for(int i = 0; i < n1; i++){
            nums1[i] = (um.count(nums1[i])) ? um[nums1[i]] : -1; 
        }

        return nums1;
    }
};