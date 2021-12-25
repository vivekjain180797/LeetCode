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

class Compare {
    public :
    bool operator()(const ListNode* l, const ListNode* r){
        return l->val > r->val;
    }
};

/* the main idea is that push the frontier in queue and maintian a queke of size k and pop element and create  link list */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /* we have to include <queue> to use it 
         * By default STL priority queue is max heap --> top is largest element
         * To create a min heap we need to pass a comparator class or struct.
        */
        priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        
        for(auto l : lists){
            if(l) q.push(l);
        }
        
        if(q.empty()) return NULL;
        
        ListNode* result = q.top();
        q.pop();
        ListNode *tail = result;
        if(tail->next) q.push(tail->next);
        while(!q.empty()){
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return result;
    }
};