class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int &n: nums){
            temp.push_back(to_string(n));
        }

        sort(temp.begin(), temp.end(), [](const string &n1, const string &n2){
            return (n2 + n1) < (n1 + n2);
        });

        if(temp[0] == "0")
            return "0";

        string res = "";
        for(string &s: temp){
            res.append(s);
        }

        return res;
    }
};