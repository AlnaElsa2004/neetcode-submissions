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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *prev=nullptr;
        ListNode *cur=slow->next;
        slow->next=nullptr;
        while(cur!=nullptr){
            ListNode *temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        ListNode *list1=head;
        ListNode *list2=prev;
        while(list2!=nullptr){
            ListNode *temp1=list1->next;
            ListNode *temp2=list2->next;
            list1->next=list2;
            list2->next=temp1;
            list1=temp1;
            list2=temp2;
        }
        
        
    }
};
