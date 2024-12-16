class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = s1.size();
        // int n2 = s2.size();
        vector<pair<char, char>> temp;

        int i = 0;
        while(i < n1){
            if(s1[i] != s2[i]){
                temp.push_back({s1[i], s2[i]});
                if(temp.size() > 2)
                    return false;
            }
            i++;
        }

        if(temp.size() == 1)
            return false;
        if(temp.size() == 0)
            return true;
        if((temp[0].first == temp[1].second) && (temp[0].second == temp[1].first))
            return true;
        
        return false;
    }
};