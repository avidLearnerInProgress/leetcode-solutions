class LRUCache {
    int capacity;
    list<int> keys;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if(mp.find(key) != mp.end()) { //key already exists in map
            keys.erase(mp[key].second); //remove key from list
            keys.push_front(key); //push the key to front
            mp[key].second = keys.begin(); //update map
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) { //key already exists in the map
            //same operations as that of get operation
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key] = {value, keys.begin()};
        }
        else {
            if(keys.size() == capacity) {
                mp.erase(keys.back()); //update map by removing last element
                keys.pop_back(); //pop last element from list =
            }
            //insert in beginning of the keys and update the map accordingly
            keys.push_front(key);
            mp[key] = {value, keys.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
