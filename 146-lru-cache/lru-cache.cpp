class LRUCache {
public:
list<int>dll;
unordered_map<int, pair<list<int>::iterator, int>> mp;
int n;
    LRUCache(int capacity) {
      n=capacity;  
    }
    void makefirst(int key){
       dll.erase(mp[key].first);
    dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
       int val=mp[key].second;
       makefirst(key);
       return val;
    }
    
    void put(int key, int value) {
      if (mp.find(key) != mp.end()) 
      { mp[key].second = value; 
      makefirst(key); 
      }
        else{
            
            dll.push_front(key);
            mp[key]={dll.begin(),value};
             n--;
        }
        if(n<0){
                int key_tobe_del=dll.back();
                dll.pop_back();
                n++;
                mp.erase(key_tobe_del);
            }
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */