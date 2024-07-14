class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());

        int i = 0;
        while(i < n){
            if(formula[i] == '('){
                st.push(unordered_map<string, int>());
                i++;
            }
            else if(formula[i] == ')'){
                unordered_map<string, int> curr = st.top();
                st.pop();
                i++;

                //check if theres a digit ahead, if so multiply it with whole bracket
                string multi = "";
                while(i < n && isdigit(formula[i])){
                    multi.push_back(formula[i]);
                    i++;
                }

                if(!multi.empty()){
                    int multiplyInt = stoi(multi);
                    for(auto &it: curr){
                        curr[it.first] = it.second * multiplyInt;
                    }
                }

                //push the multiplied bracket by merging it with existing top
                for(auto &it: curr){
                    st.top()[it.first] += it.second;
                    //if the same element already exists, new count will be added in it 
                }
            }
            else{
                //if it is fresh element, then form element
                string currElement = "";
                currElement.push_back(formula[i]);
                i++;
                while(i < n && (isalpha(formula[i])) && islower(formula[i])){
                    currElement.push_back(formula[i]);
                    i++;
                }

                //handle digits
                string currCount = "";
                while(i < n && isdigit(formula[i])){
                    currCount.push_back(formula[i]);
                    i++;
                }

                int currCountDigit = (currCount.empty()) ? 1 : stoi(currCount);
                st.top()[currElement] += currCountDigit;
            }
        }

        //sort the res - as we are merging always, the stack top at last will contain the final unsorted string
        string ans = "";
        map<string, int> mp(begin(st.top()), end(st.top()));
        for(auto &it: mp){
            ans += it.first;
            if(it.second > 1){
                ans += to_string(it.second);
            }
        }

        return ans;
    }
};