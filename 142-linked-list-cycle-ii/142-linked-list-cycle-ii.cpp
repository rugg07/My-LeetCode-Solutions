/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode *slow=head, *fast=head;
        while(slow!=NULL)
        {
            if(slow==fast)
                return slow->next;
            else
            {
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return NULL;
    }
};*/

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