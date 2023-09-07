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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
            return head;
        ListNode* oddCur = head;
        ListNode* oddHead = oddCur;
        ListNode* evenCur = head->next;
        ListNode* evenHead = evenCur;
        ListNode* cur = head->next->next;
        bool odd = true;
        while(cur!=nullptr){
            if(odd){
                oddCur->next = cur;
                oddCur = oddCur->next;
            }
            else{
                evenCur->next = cur;
                evenCur = evenCur->next;
            }
            cur = cur->next;
            odd^=true;
        }
        oddCur->next = evenHead;
        evenCur->next = nullptr;
        return oddHead;
    }
};