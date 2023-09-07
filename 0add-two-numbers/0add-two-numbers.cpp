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
        while(l1!=nullptr || l2!=nullptr || carry) {
            int cur = 0;
            if(l1!=nullptr){
                cur+=l1->val;
                l1 = l1->next;
            }
            if(l2!=nullptr){
                cur+=l2->val;
                l2 = l2->next;
            }
            cur += carry;
            carry = cur > 9 ? 1 : 0;
            prev->next = new ListNode(cur % 10);
            prev = prev->next;
        }
        return dummy->next;
    }
};