class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        stack<int> st;
        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() && st.top() < nums2[i]){
                um[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++){
            nums1[i] = (um.count(nums1[i])) ? um[nums1[i]] : -1;
        }
        
        return nums1;
    }
};