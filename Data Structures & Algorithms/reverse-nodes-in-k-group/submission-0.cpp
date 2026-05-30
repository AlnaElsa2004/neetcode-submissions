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
 ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *prev=nullptr;
        ListNode *cur=head;
        while(cur!=nullptr){
            ListNode *temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1)
            return head;
        ListNode *l1=head;
         ListNode *l2=head;
        int count=0;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        while(l1!=nullptr){
            count++;
            if(count==k){
                ListNode* nextnode=l1->next;
                l1->next=nullptr;
                ListNode *newhead=reverseList(l2);
                prev->next=newhead;
                l2->next=nextnode;
                prev=l2;
                l2=nextnode;
                l1=nextnode;
                count=0;
            }else{
                l1=l1->next;
            }
        }
        return dummy->next;
    }
};
