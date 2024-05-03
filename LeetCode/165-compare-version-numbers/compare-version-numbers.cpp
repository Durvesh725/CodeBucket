class Solution {
private:
    //custom string split function
    vector<int> splitString(char delimiter, string &s){
        vector<int> ans;
        int start = 0;
        int end = s.find(delimiter);
        while(end != string::npos){
            string substr = s.substr(start, end-start);
            ans.push_back(stoi(substr));
            start = end + 1;
            end = s.find(delimiter, start);
        }

        string temp = s.substr(start, end-start);
        ans.push_back(stoi(temp));
        return ans;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> n1 = splitString('.', version1);
        vector<int> n2 = splitString('.', version2);
        for(auto it: n1)    cout << it << " ";
        cout << endl;
        for(auto it: n2)    cout << it << " ";
        cout << endl;
        int n1s = n1.size();
        int n2s = n2.size();
        int val1, val2;
        for(int i = 0; i < max(n1s, n2s); i++){
            val1 = (i < n1s) ? n1[i] : 0;
            val2 = (i < n2s) ? n2[i] : 0;

            if(val1 < val2)  return -1;
            else if(val1 > val2) return 1;
        }
        return 0;
    }
};