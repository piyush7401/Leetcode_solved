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
    ListNode* partition(ListNode* head, int x) {
        map<int,int> m;
        
        ListNode* temp = head;
        
        ListNode* tempy = head;
        
        int i =0;
        
        while(temp != NULL){
            m.insert({i,temp->val});
            i++;
            temp = temp -> next;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        for(auto it : m){
            cout<<it.first<<" "<<it.second<<"\n";
            if(it.second < x){
                head -> val = it.second;
                head = head -> next;
            }
            else if(it.second >= x){
                q.push({it.first,it.second});
            }
        }
        
        while(head != NULL){
            cout<<q.top().first<<" "<<q.top().second<<"\n";
            head -> val = q.top().second;
            head = head -> next;
            q.pop();
        }
        
        return tempy;
    }
};