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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
            return nullptr;
        int len = 0;
        for(auto p = head; p!=nullptr; p=p->next)
            len++;
        
        k = k % len;
        
        if(k==0)
            return head;
        
        
        ListNode* n2 = nullptr;
        ListNode* prev = nullptr;
        for(ListNode* p = head; p!=nullptr; p = p->next){
            n2 = (n2==nullptr ? nullptr : n2->next);
            if(k-- == 0){
                n2 = head;
            }
            if(p->next == nullptr)
                prev = p;
        }
        
        ListNode* newHead = n2->next;
        n2->next = nullptr;
        prev->next = head;
        
        return newHead;
    }
};