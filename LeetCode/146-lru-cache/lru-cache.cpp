class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int> > mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;    
    }
    
    void makeMostRecent(int &key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();    //dll.begin() return the address of starting node -> update node's addr
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;

        //make that key as LRU node
        makeMostRecent(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        //if for key value exists, update val make it fresh
        if(mp.find(key) != mp.end()){
            makeMostRecent(key);
            mp[key].second = value;
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){
            int key_to_be_del = dll.back();
            mp.erase(key_to_be_del);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */