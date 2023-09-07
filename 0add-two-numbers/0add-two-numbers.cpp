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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        int carry = 0;
        while(l1!=nullptr && l2!=nullptr){
            int cur_val = l1->val + l2->val + carry;
            if(cur_val>9){
                carry = 1;
                cur_val = cur_val % 10;
            }
            else {
                carry = 0;
            }
            prev->next = new ListNode(cur_val);
            prev = prev->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1==nullptr)
            swap(l1, l2);
        while(l1!=nullptr){
            int cur_val = l1->val + carry;
            if(cur_val>9){
                carry = 1;
                cur_val = cur_val % 10;
            }
            else {
                carry = 0;
            }
            prev->next = new ListNode(cur_val);
            prev = prev->next;
            l1 = l1->next;
        }
        if(carry > 0)
            prev->next = new ListNode(1);
        return dummy->next;
    }
};