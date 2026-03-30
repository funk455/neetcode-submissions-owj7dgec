class Node{
public:
    int key;
    int val;
    Node * prev;
    Node * next;
    Node(int k,int v): key(k),val(v),prev(nullptr),next(nullptr) {}
};
class LRUCache {
private:
    void remove(Node * node) {
        Node * prev = node->prev;
        Node * next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node * node) {
        Node * n = right->prev;
        n->next = node;
        node->prev = n;
        node->next = right;
        right->prev = node;
    }
public:
    int cap;
    unordered_map<int,Node*> cache;
    Node * left;
    Node * right;
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if ( cache.find(key)!=cache.end()) {
            Node * temp = cache[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node * newn = new Node(key,value);
        cache[key] = newn;
        insert(newn);
        if ( cache.size()>cap) {
            Node * lru = left -> next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
