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
    ListNode* rotateRight(ListNode* head, int k) {
        //OPTIMAL: using list length (iterative)
        
//if no node or 1 node exists no rotation can occur same when k=0 no rotation can occur
      if (head==NULL || head->next==NULL || k == 0) 
          return head;
        
        ListNode *cur = head; //start from head node
        
        //count length of the list
        int list_length=1;
        while(cur->next!=NULL)
        {
            cur=cur->next;
            list_length++;
        }
        
        //make it as a cycle/circle such that last node points to head
       cur->next = head;
        
        //if k>length of the list, it will reduce the no. of rotations
        k = k%list_length; 
        
        //to find which node would become the last node after k rotations
        list_length = list_length-k; 
        while(list_length>0)
        {
            cur = cur->next;
            list_length--;
        }
        
        //make the node after last node for k rotations as the head node
        head = cur->next;
        cur->next=NULL; //make the last node (which we are pointing to) point to NULL
        
        return head;
    }
};
//TC: O(n)+O(n-(n%k))=O(n) [count total length + traverse till that node for k iteration]
//SC: O(1)