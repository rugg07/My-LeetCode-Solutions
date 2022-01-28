/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* The first node after which both lists point to same ele
eg: A=[4,1,8,4,5], B=[5,6,1,8,4,5] (both lists have 8,4,5 so ele 8 is intersecting node)*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //BRUTE FORCE:
        
        ListNode *temp = headB; // point to head of second list
    
        while(headA != NULL) //traverse till last node
        {
        
            while(headB != NULL)
            {
            
                if(headA == headB) //if both list point to same node 
                    return headA;
                
                headB = headB->next; //move forward in second list
            }
            
            headA = headA->next; //move forward in first list
            //point headB to its head node to start over again with another ele of headA
            headB = temp; 
        }
        return headA; //return the intersected node
    }
};
//TC: O(m*n) [traversing listA * with each ele of list B at one time]
//SC: O(1)