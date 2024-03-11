#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char, int> mp;

        for (auto it : s) {
            mp[it]++;
        }

        for (auto it : order) {
            if (mp.find(it) != mp.end()) {
                while (mp[it] > 0) {
                    ans += it;
                    mp[it]--;
                }
                mp.erase(it);
            }
        }

        for (auto& it : mp) {
            while (it.second > 0) {
                ans += it.first;
                it.second--;
            }
        }

        return ans;
    }
};
