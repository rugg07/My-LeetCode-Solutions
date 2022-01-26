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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //similar to adding two ele in linked list
        
        ListNode* dummy = new ListNode(); //to make new head of new list
        ListNode* temp = dummy;//points to the new head
        
        //we check if curr ele is null not ->next!=NULL
        //do && so it breaks loop only when both lists go to null
        while(list1!=NULL && list2!=NULL) 
        {
            int node=0; //stores the values
            
            if(list1->val <= list2->val )
            {
                node=list1->val;
                list1=list1->next; //go to next ele
            }
            else
            {
                node=list2->val;
                list2=list2->next;
            }
            
            //store the value by creating new node on each iteration
            ListNode* newNode = new ListNode (node); 
            temp->next= newNode; //make next ele have same value as the newNode created
            temp=temp->next; //go to next ele
        }
        
        if(list1) 
            temp->next = list1;   //if we have only list1 ele remaining
      
        if(list2) 
            temp->next = list2;   //if we have only list2 ele remaining
        
        return dummy->next; //first ele is 0 since new node so head node is dummy->next
        
    }
};
//TC: O(max(n1,n2)) [max of (size of list1, size of list2)]
//SC: O(n) [creating new list of n ele]