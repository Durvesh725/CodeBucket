class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2){
            return 0;
        }

        set<int> st;
        for(int &n: arr){
            st.insert(n);
        }

        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int p1 = arr[i];
                int p2 = arr[j];
                int len = 2;
                while(st.find(p1+p2) != st.end()){
                    len++;
                    maxi = max(maxi, len);
                    int temp = p2;
                    p2 = p1 + p2;
                    p1 = temp;
                }
            }
        }

        return maxi >= 3 ? maxi : 0;
    }
};