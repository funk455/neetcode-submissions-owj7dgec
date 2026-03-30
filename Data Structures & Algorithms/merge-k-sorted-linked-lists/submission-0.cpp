/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//合并多个排好序的链表
class Solution {
public:
    //arry2list
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return nullptr;
        std::vector<int> nodes;
        for (auto lst : lists){
            while(lst){
                nodes.push_back(lst->val);
                lst = lst->next;
            }
        }
        sort(nodes.begin(),nodes.end());
        ListNode * res = new ListNode(0);
        ListNode * cur = res;
        for (int node : nodes) {
            cur->next = new ListNode(node);
            cur = cur->next;
        }
        return res->next;
    }
};
