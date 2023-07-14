class LRUCache {
public:
    unordered_map<int,int>mp;
    unordered_map<int,list<int>::iterator>address;
    list<int>l;
    int cap;
    int size;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        list<int>::iterator it = address[key];
        l.erase(it);
        l.push_front(key);
        address[key] = l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
       if(mp.find(key) != mp.end()){
           l.erase(address[key]);
           size--;
       }
       if(size == cap){
           int k = l.back();
           l.pop_back();
           address.erase(k);
           mp.erase(k);
           size--;
       }
       size++;
       l.push_front(key);
       mp[key] = value;
       address[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
