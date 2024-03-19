class Solution {
public:
    string minimizeStringValue(string s) {
        int n=s.length();
        set<pair<int,char>> st;
        map<char,int> mp;
        for(char ch='a';ch<='z';ch++) {
            st.insert({0,ch});
        }
        for(auto x:s) {
            if(x!='?') {
                st.erase({mp[x],x});
                mp[x]++;
                st.insert({mp[x],x});
            }
        }
        string ans;
        for(int i=0;i<n;i++) {
            char ch=s[i];
            if(ch!='?') {
                continue;
            }
            auto it=*st.begin();
            int occ=it.first;
            char character=it.second;
            st.erase({occ,character});
            ans+=character;
            st.insert({occ+1,character});
        }
        sort(ans.begin(),ans.end());
        int j=0;
         for(int i=0;i<n;i++) {
            if(s[i]=='?') {
                s[i]=ans[j];
                j++;
            }
         }
        return s;
    }
};