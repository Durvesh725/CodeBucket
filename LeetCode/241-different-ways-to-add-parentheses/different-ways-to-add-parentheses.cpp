class Solution {
public:
    vector<int> solve(string exp){
        vector<int> ans;
        int n = exp.size();

        for(int i = 0; i < n; i++){
            if(exp[i] == '*' || exp[i] == '-' || exp[i] == '+'){
                vector<int> leftRes = solve(exp.substr(0, i));
                vector<int> rightRes = solve(exp.substr(i+1));

                for(auto n1: leftRes){
                    for(auto n2: rightRes){
                        if(exp[i] == '*')
                            ans.push_back(n1 * n2);
                        if(exp[i] == '+')
                            ans.push_back(n1 + n2);
                        if(exp[i] == '-')
                            ans.push_back(n1 - n2);
                    }
                }
            }
        }

        if(ans.empty())
            ans.push_back(stoi(exp));
        
        return ans;
    }

    vector<int> diffWaysToCompute(string exp) {
        return solve(exp);
    }
};