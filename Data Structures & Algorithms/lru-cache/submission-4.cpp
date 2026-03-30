class LRUCache {
public:
vector<pair<int,int>> cache;
int cap;
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first ==key) {
                auto item = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back({key,item.second});
                return item.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        //更新
        for (int i = 0; i < cache.size(); i++) {
            if ( cache[i].first == key) {
                //常规不可取
                //chache[i].second = value;
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
        }
        if ( cache.size() == cap) {
            cache.erase(cache.begin());
        }
        cache.push_back({key,value});
    }
};
