class Solution {
public:
    int findMaxK(vector<int>& num) {
        unordered_set<int> s;
        int res = 0;
        for(int i = 0; i < num.size(); i++){
            if(num[i] > 0){
                if(s.find(-(num[i])) != s.end()){
                    res = max(res, num[i]);
                }
                s.insert(num[i]);
            }
            else{
                if(s.find(-(num[i])) != s.end()){
                    res = max(res, -(num[i]));
                }
                s.insert(num[i]);
            }
        }
        return (res == 0) ? -1 : res;
    }
};