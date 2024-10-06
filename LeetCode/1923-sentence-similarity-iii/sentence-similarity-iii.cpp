class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        vector<string> v1;
        vector<string> v2;

        string word = "";
        int len = 0;

        while (ss1 >> word) {
            v1.push_back(word);
            len++;
        }
        v1.resize(len);

        word = "";
        len = 0;

        while (ss2 >> word) {
            v2.push_back(word);
            len++;
        }
        v2.resize(len);

        string lcp = "";  
        string lcs = "";  

        int n = v1.size();
        int m = v2.size();

        int sp1 = 0;
        while (sp1 < min(n, m) && v1[sp1] == v2[sp1]) {
            if (!lcp.empty()) lcp += " "; 
            lcp += v1[sp1];
            sp1++;
        }

        int sp2 = 0;
        int i = n - 1, j = m - 1;
        while (i >= sp1 && j >= sp1 && v1[i] == v2[j]) {
            if (!lcs.empty()) lcs = " " + lcs; 
            lcs = v1[i] + lcs;
            i--, j--;
            sp2++;
        }

        if (sp1 + sp2 == min(n, m)) {
            return true;
        }

        if (sp1 <= i) {
            return false;
        }

        return true;
    }
};
