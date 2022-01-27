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
       //OPTIMAL: inplace (not creating external/new nodes)
        
        ListNode *start = new ListNode();               //false head
      ListNode *tmp = start;                          //working node 
      
      while(list1 && list2){                                //if we have two lists
        if(list1->val < list2->val){tmp->next = list1; list1 = list1->next;}
        else {tmp->next = list2; list2 = list2->next;}
        tmp = tmp->next;
      }
      if(list1) tmp->next = list1;     //if we have only list1 or we have remain as list1
      if(list2) tmp->next = list2;     //if we have only list2 or we have remain as list2
      return start->next;            //return real head
    }
};

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //BRUTE FORCE: similar to adding two ele in linked list
        
        ListNode* dummy = new ListNode(); //to make new head of new list
        ListNode* temp = dummy;//points to the new head
        
        if(l1==NULL) //list 1 empty
            return list2;
     
        if(l2==NULL) //list 2 empty
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
*/