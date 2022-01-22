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
    ListNode* middleNode(ListNode* head) {
        //OPTIMAL: (Tortoise method)
        ListNode* slow = head;
        ListNode* fast = head;
        
        //neither the next ele after fast=Null (odd) nor fast should point to NULL (even)
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next; //move one step at a time
            fast=fast->next->next; //move two step at a time
        }
        return slow;//when fast points to null it means slow has reached the middle ele
    }
};
//TC: O(n/2) [fast pointer covers n ele faster (takes 2 steps at a time)]
//SC: O(1)


/*---------------------------------------------------------------------------------------

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //BRUTE FORCE
        ListNode* current = head; //keep dummy pointer pointing to head
        int count=1; //to count total number of ele 
        int iteration=1; //to count iteration number
        
        while(current->next!=NULL) //count all ele in list
        {
            count++;
            current=current->next;
        }
        
        //this applies to both odd and even no.s
        count=(count/2)+1;//+1 for even because we want the node after middle node
        
        if(count%2==0) //Even no.s
        {
            ListNode* current=head; //start from head again else it shows last ele
            while(current->next!=NULL)
            {
               if(iteration==count) //once we reach middle ele just return the node 
               {
                   return current;
               }
                iteration++;
               current=current->next;
            } 
        }
        if(count%2!=0) //Odd no.s
        {
            ListNode* current=head;
            while(current->next!=NULL)
            {
               if(iteration==count)
               {
                   return current;
               }
                  iteration++;
               current=current->next;
            } 
        }
        return current; //if nothing is possible just show current node = dummy pointer.
    }
};
//TC: O(n) + O(n/2) [traverse n ele for counting + till n/2 to find middle node]
//SC: O(1)

*/