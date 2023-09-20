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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> M;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]!=nullptr)
                M.insert({lists[i]->val, lists[i]});
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        
        while(!M.empty()){
            auto it = M.begin();
            int curNum = it->first;
            ListNode* curNode = it->second;
            ListNode* tmp = new ListNode();
            tmp->val = curNum;
            cur->next = tmp;
            cur = cur->next;
            
            M.erase(it);
            if(curNode->next){
                curNode = curNode->next;
                M.insert({curNode->val, curNode});
            }
        }
        
        return dummy->next;
    }
};