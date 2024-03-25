class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> um;
        for(int i = 0; i < hand.size(); i++)
            um[hand[i]]++;

        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); i++){
            if(um[hand[i]] == 0)
                continue;

            for(int j = 0; j < groupSize; j++){
                int curr = hand[i] + j;

                if(um[curr] == 0)
                    return false;

                um[curr]--;
            }
        }
        return true;
    }
};