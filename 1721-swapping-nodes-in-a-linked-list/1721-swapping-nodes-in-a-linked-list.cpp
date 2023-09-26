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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = nullptr;
        ListNode* n2 = nullptr;
        k--;
        for(ListNode* cur = head; cur!=nullptr; cur = cur->next){
            n2 = (n2==nullptr ? nullptr : n2->next);
            if(k-- == 0){
                n1 = cur;
                n2 = head;
            }
        }
        
        swap(n1->val, n2->val);
        return head;
    }
};