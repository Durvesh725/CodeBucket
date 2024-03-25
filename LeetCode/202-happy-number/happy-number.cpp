class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> um;
        
        while (n != 1) {
            if (um.find(n) != um.end()) {
                return false; 
            }
            um.insert(n);  
            int num = 0;
            while (n) {
                int d = n % 10;
                num += d * d;
                n = n / 10;
            }
            n = num;  
        }
        return true;
    }
};
