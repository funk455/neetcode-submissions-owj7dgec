class Node{
    public:
    int val;
    Node * next;
    Node(int v):val(v),next(nullptr){}
    Node(int v,Node * p):val(v),next(p) {}
};
class LinkedList {
public:
    Node * head;
    Node * tail;
    LinkedList() {
        head = new  Node(-1);
        tail = head;
    }

    int get(int index) {
        Node * cur = head->next;
        int i = 0;
        while(cur!=nullptr){
            if (i == index) return cur->val;
            cur = cur->next;
            i++;
        }
        return -1;
    }

    void insertHead(int val) {
        Node * newn = new Node(val);
        newn->next = head->next;
        head->next = newn;
        if (newn->next == nullptr) tail = newn;
    }
    
    void insertTail(int val) {
        tail->next = new Node(val);
        tail = tail->next;
    }

    bool remove(int index) {
        Node * cur = head;
        int i = 0;
        while(i<index && cur!=nullptr){
            i++;
            cur = cur->next;
        }
        if ( cur!=nullptr && cur->next!=nullptr) {
            if (cur->next == tail){
                tail = cur;
            }
            auto del = cur->next;
            cur->next = cur->next->next;
            delete del;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        auto cur = head->next;
        vector<int> res;
        while(cur!=nullptr) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};
