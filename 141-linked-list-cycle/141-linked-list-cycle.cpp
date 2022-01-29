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
    bool hasCycle(ListNode *head) {
        //OPTIMAL: Two-pointer approach (slow & fast)
        
        //no ele in the list OR only 1 ele in list so no cycle is possible
        if(head==NULL || head->next==NULL) 
            return false;
        
        //make two pointers that point to the head node
        ListNode *slow = head;
        ListNode *fast = head;
        
        //traverse until both dont point to NULL
        //do fast->next!=NULL to check if we standing at last node and next ele is NULL
        while(fast!=NULL && slow!=NULL && fast->next!=NULL)
        {
            slow=slow->next; //move by 1 step
            fast=fast->next->next; //move by 2 steps
            
            if(fast==slow) //cycle is present
                return true;
        }
        return false; //no cycle was found OR slow and fast point to NULL
    }
};
//TC: O(n) [traverse through the list]
//SC: O(1)

/*----------------------------------------------------------------------------------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //BRUTE FORCE: using hashMap
        
        //no ele in the list OR only 1 ele in list so no cycle is possible
        if(head==NULL || head->next==NULL) 
            return false;
        
        unordered_map<ListNode*, int> map; //store the node and count
        
        ListNode * dummy = head; //pointer for the list
        
        while(dummy!=NULL)
        {
            map[dummy]++; //update count of the node in hashmap
            
            if(map[dummy]>1) //if count>1 means node is repeating
                return true;
            
            dummy = dummy->next;//go to next node
        }
        return false;
    }
};
//TC: O(n) [traverse through list]
//SC: O(n) [hashMap to store all n ele]
*/