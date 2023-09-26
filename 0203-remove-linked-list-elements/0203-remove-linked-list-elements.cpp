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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode{};
        ListNode* dummy = prev;
        prev->next = head;
        while(head){
            ListNode* next = head->next;
            if(head->val == val){
                prev->next = next;
                head = next;
            }
            else{
                prev = head;
                head = next;
            }
        }
        return dummy->next;
    }
};