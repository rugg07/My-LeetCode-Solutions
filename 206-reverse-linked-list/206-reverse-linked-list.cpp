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
            ListNode* next = head -> next; //points to next ele after head
            
            //head->next connection going right is broken and now points to dummy node
            head->next=newHead;
            
            newHead=head; //the dummy node becomes the new head node
            head=next; //original head node takes the pos of head->next ele as head node
        }
        return newHead; //this finally points to the begining (when reversed)
    }
};
//TC: O(n) [changing for n elements]
//SC: O(1) [because we only reversed given linked list]
