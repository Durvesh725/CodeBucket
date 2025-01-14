class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> um;
        int n = A.size();
        vector<int> ans;

        int cnt = 0;
        for(int i = 0; i < n; i++){
            um[A[i]]++;
            um[B[i]]++;

            if(A[i] != B[i]){
                if(um[A[i]] >= 2)
                    cnt++;
                if(um[B[i]] >= 2)
                    cnt++;
            }
            else{
                cnt += 1;
            }

            ans.push_back(cnt);
        }

        return ans;
    }


};