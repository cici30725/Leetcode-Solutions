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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)
            return head;
        
        ListNode* cur = head;
        ListNode* res = head;
        if(head->next)
            res = head->next;
        
        ListNode* prev = nullptr;
        while(cur!=nullptr && cur->next!=nullptr){
            ListNode* nextNode = cur->next;
            ListNode* nextnextNode = nextNode->next;
            nextNode->next = cur;
            cur->next = nextnextNode;
            if(prev)
                prev->next = nextNode;
            
            prev = cur;
            cur = nextnextNode;
        }
        return res;
    }
};