class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int s = 0, c = 0;
        for(auto x: students){
            if(x == 1)  s++;
            else    c++;
        }

        for(auto sand: sandwiches){
            if(sand){
                if(s > 0)   s--;
                else 
                    return c;
            }
            else{
                if(c > 0)   c--;
                else    
                    return s;
            }
        }
        return 0;
    }
};