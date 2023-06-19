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
        ListNode* cur = head;
        ListNode* prev = nullptr;
        vector<pair<ListNode*, ListNode*>> vec;
        ListNode* first_node = nullptr;
        bool flag = false;
        
        int cnt = 0;
        while(cur!=nullptr){
            if(cnt==0)
                first_node = cur;
            if(cnt==k-1){
                vec.push_back(make_pair(first_node, cur));
            }
                
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt = (cnt+1)%k;
        }
        first_node->next = nullptr;
        if(cnt!=0){
            vec.push_back(make_pair(first_node, prev));
            flag = true;
            
            cur = prev;
            prev = nullptr;
            while(cur!=nullptr){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
        }
        
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i].first->val<<" "<<vec[i].second->val<<endl;
        }
        
        for(int i=0; i<vec.size()-1; i++){
            ListNode* first = vec[i].first;
            ListNode* second = vec[i].second;
            if(i<vec.size()-2)
                first->next = vec[i+1].second;
            else{
                if(flag)
                    first->next = vec[i+1].first;
                else
                    first->next = vec[i+1].second;
            }
        }
        
        return vec[0].second;
        
    }
};