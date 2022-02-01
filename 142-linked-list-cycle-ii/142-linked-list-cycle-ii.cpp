/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
         //no ele in the list OR only 1 ele in list so no cycle is possible
        if(head==NULL || head->next==NULL) 
            return NULL;
        
        ListNode *slow=head, *fast=head, *entry=head; 
        
       while(fast!=NULL && fast->next!=NULL)
       {
           //move slow & fast to find its collision in the cycle
           slow=slow->next;
           fast=fast->next->next;
           
        //once collided, use entry starting from head and slow to find first node in cycle
           if(slow==fast)
           {
               while(slow!=entry)
               {
                   slow=slow->next;
                   entry=entry->next;
               }
               return entry;
           }
       }
        return NULL;
    }
};
//TC: aprox. O(n) [if fast pointer takes more turns in cycle otherwise traversing n nodes]
//SC: O(1)
/*----------------------------------------------------------------------------------------
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     //BRUTE FORCE: using hashMap (Same as Detect cycle in Linked List)
        
        //no ele in the list OR only 1 ele in list so no cycle is possible
        if(head==NULL || head->next==NULL) 
            return NULL;
        
        unordered_map<ListNode*, int> map; //store the node and count
        
        ListNode * dummy = head; //pointer for the list
        
        while(dummy!=NULL)
        {
            map[dummy]++; //update count of the node in hashmap
            
            if(map[dummy]>1) //if count>1 means node is repeating
                return dummy;
            
            dummy = dummy->next;//go to next node
        }
        return NULL;
    }
};
//TC: O(n) [traverse through list]
//SC: O(n) [hashMap to store all n ele]
*/