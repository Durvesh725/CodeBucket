class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> um;
        int n = nums2.size();
        for(int i = 0; i < n; i++){
            um[nums2[i] * k]++;
        }

        long long good_pairs = 0;
        for(auto &num: nums1){
            for(int i = 1; i <= sqrt(num); i++){
                if(num % i == 0){
                    int f1 = i;
                    int f2 = num / i;

                    if(f1 != f2 && um.find(f1) != um.end())
                        good_pairs += um.at(f1);

                    if(um.find(f2) != um.end())
                        good_pairs += um.at(f2);
                }
            }
        }

        return good_pairs;
    }
};