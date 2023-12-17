class FoodRatings {
public:
    //comparator to compare food with requirements as per the highest rating
    struct comp{
        bool operator()(const pair<int, string> l, const pair<int, string> r) const{
            //if the rating is not equal, return the highest rating
            if(l.first != r.first)
                return l.first > r.first;
            else
                //if same rating, return lex smaller food string
                return l.second < r.second;
        }   
    };
    
    //key: cusine, value: set:{{rating, food}, {rating2, food2. artingm, foodn}}
    unordered_map<string, set<pair<int, string>, comp>> cusineToFood;
    
    //create mapping between food and cusine
    unordered_map<string, string> foodToCusine;
    
    //create mapping bet rating and foor
    unordered_map<string, int> rate;
    
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for(int i = 0; i < f.size(); i++){
            cusineToFood[c[i]].insert({r[i], f[i]});
            
            //these two maps are required further in the change rating func just to update the record
            foodToCusine.insert({f[i], c[i]});
            rate.insert({f[i], r[i]});
        }
    }
    
    void changeRating(string f, int nr) {
        int r = rate[f];
        
        //update in rate to food mapping for further processing
        rate[f] = nr;
        
        //update in the main mapping
        string c = foodToCusine[f];
        cusineToFood[c].erase({r, f});
        cusineToFood[c].insert({nr, f});
    }
    
    string highestRated(string c) {
        pair<int, string> p = *cusineToFood[c].begin();
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */