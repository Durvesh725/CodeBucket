class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 0;
        unordered_map<int, int> um;
        int max_fruits = 0;

        while(j < n){
            um[fruits[j]]++;
            if(um.size() > 2){
                um[fruits[i]]--;
                if(um[fruits[i]] == 0)
                    um.erase(fruits[i]);
                i++;
            }
            else{
                max_fruits = max(max_fruits, j - i + 1);
            }
            j++;
        }

        return max_fruits;
    }
};