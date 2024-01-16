class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> um;
    RandomizedSet() {
        
    }
    
    bool search(int val){
        if(um.find(val) != um.end())
            return true;
        return false;
    }
    
    bool insert(int val) {
        if(search(val)){
            return false;
        }
        v.push_back(val);
        //store index
        um[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)){
            return false;
        }
        auto it = um.find(val);
        //back points to the current ele
        v[it -> second] = v.back();
        v.pop_back();
        
        //remove from map
        um[v[it->second]]=it->second;
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */