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

/*class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       //OPTIMAL: inplace (not creating external/new nodes)
        
        if(list1==NULL) //list 1 empty
            return list2;
     
        if(list2==NULL) //list 2 empty
            return list1;
        
        if(list1->val > list2->val)
            swap(list1,list2); //make list with first ele smallest as list1 (final list)
        
        ListNode* result = list1; //points to list with 1st smaller ele (head node)
        
        while(list1!=NULL && list2!=NULL)
        {
            ListNode* temp = NULL; //to store the value of smaller ele from other list
            
            //go till end of list1, since list1 will be connecting with ele of list2
            while(list1!=NULL && list1->val <= list2->val) 
            {
                temp=list1;
                list1=list1->next;
            }
            
            temp->next=list2;  //when list2 ele is samller
            swap(list1,list2); //swap pos list1 with list2 pointer to point to smaller ele 
        }
        
        return result;
    }
};
//TC: O(n1+n2) [traversing list1 and list2]
//SC: O(1) [since we dont make a new linkedlist]
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //BRUTE FORCE: similar to adding two ele in linked list
        
        ListNode* dummy = new ListNode(); //to make new head of new list
        ListNode* temp = dummy;//points to the new head
        
        if(list1==NULL) //list 1 empty
            return list2;
     
        if(list2==NULL) //list 2 empty
            return list1;
        
        //we check if curr ele is null not ->next!=NULL
        //do && so it breaks loop only when both lists go to null
        while(list1!=NULL && list2!=NULL) 
        {
            //int node=0; //stores the values
            
            if(list1->val <= list2->val )
            {
                //since we use a pointer we directly point to node, and not int list->val
                temp->next=list1; 
                list1=list1->next; 
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }
            
            //go to next ele
            temp=temp->next;
        }
        
        if(list1) 
            temp->next = list1;   //if we have only list1 ele remaining
      
        if(list2) 
            temp->next = list2;   //if we have only list2 ele remaining
        
        return dummy->next; //first ele is 0 since new node so head node is dummy->next
        
    }
};
//TC: O(n1+n2) [traverse list1 and list 2]
//SC: O(n1+n2) => O(n) [creating new list of n ele]
