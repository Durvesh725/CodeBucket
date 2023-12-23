class Solution {
public:
    bool isPathCrossing(string path) {
        //reason behind using us is that insertion is in 0(1), so n ele O(n)
        //set: TC: O(nlogn)
        //cannot store complex datatypes such aa pair<int, int> in an unordered set/map
        
        int x = 0;
        int y = 0;
        unordered_set<string> us;
        us.insert("0,0");
        
        for(char c: path){
            if(c == 'N')    y++;
            else if(c == 'E')    x++;
            else if(c == 'S')    y--;
            else    x--;
            
            string coordinate = to_string(x) + "," + to_string(y);
            if(us.find(coordinate) != us.end())
                    return true;
            else
                us.insert(coordinate);
        }
        return false;
    }
};