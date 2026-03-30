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

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy =new ListNode(0,head);
        //永远指向要操作组的第一个节点
        ListNode * gprev = dummy;
        while(true) {
            ListNode * kth = getkth(gprev,k);
            if (!kth) {
                break;
            }
            //保存终止节点
            ListNode * groupnext = kth->next;
            ListNode * prev = kth->next;
            ListNode * cur = gprev->next;
            //翻转组内节点
            while(cur!=groupnext) {
                auto temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            //将节点嵌入链表,准备下一次循环
            auto temp = gprev->next;
            gprev->next = kth;
            gprev = temp;
        }
        return dummy->next;
    }
    ListNode * getkth(ListNode * node,int k) {
        while(node && k>0) {
            node = node->next;
            k--;
        }
        return node;
    }
};
