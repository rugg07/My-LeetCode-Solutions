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
            ListNode* next = head -> next; //points to next var after head
            head->next=newHead; //next var after head becomes the dummy value (since  we reverse dir.)
            newHead=head; //the dummyValue becomes the head node
            head=next; //the new dummy which is head node points to next var after head 
        }
        return newHead;
    }
};
//TC: O(n) [changing for n elements]
//SC: O(1) [because we only reversed given linked list]
