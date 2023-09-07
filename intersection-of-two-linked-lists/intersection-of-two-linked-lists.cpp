/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int a_cnt = 0, b_cnt = 0;
        while(curA!=nullptr || curB!=nullptr){
            if(curA!=nullptr){
                a_cnt++;
                curA = curA->next;
            } 
            if(curB!=nullptr){
                b_cnt++;
                curB = curB->next;
            }
        }
        if(b_cnt>a_cnt){
            swap(headA, headB);
            swap(b_cnt, a_cnt);
        }
        while(a_cnt>b_cnt){
            headA = headA->next;
            a_cnt--;
        }
        while(a_cnt>0){
            if(headA == headB)
                return headA;
            a_cnt--;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};