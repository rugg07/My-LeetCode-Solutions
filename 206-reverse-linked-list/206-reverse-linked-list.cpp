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
        ListNode* newHead= NULL; //dummy 
        while(head!=NULL)
        {
            ListNode* next = head -> next; //points to next var
            head->next=newHead; //next var becomes the new head
            newHead=head; //the newHead gets value of head
            head=next; //head points to next
        }
        return newHead;
    }
};
//TC: O(n) [changing for n elements]
//sC: O(1)