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
             ListNode* removeNthFromEnd(ListNode* head, int n) {
                     int count=0;
                             ListNode *link=head;
                                     while(link!=nullptr){
                                                 count++;
                                                             link=link->next;
                                                                     }if(count == n) {
            return head->next;
        }
                                                                             int t=count-n;
                                                                             link=head;
                                                                                     for(int i=0;i<t-1;i++){
                                                                                                 link=link->next;
                                                                                                         }
                                                                                                                 link->next=link->next->next;
                                                                                                                 return head;
                                                                                                                     }
                                                                                                                     };
                                                                                                                     