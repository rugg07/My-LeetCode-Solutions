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
    ListNode* reverseKGroup(ListNode* head, int k) {
     
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next=head; //new node should point to head node
        
        //all pointers start from dummy node but take diff pos later on
        ListNode *cur = dummy, *nex = dummy, *prev = dummy; 
        
        int count=0; //since we start counting from dummy node
        
        while(cur->next!=NULL)//count number of nodes in list
        {
            cur=cur->next;
            count++;
        }
        
        while(count>=k) //reduce by k size, when count<k then new group cant be formed
        {
            cur = prev->next; //start from head node (after dummy node)
            nex = cur->next;  //start after head node (after pos of cur (head node))
            
            for(int i=1; i<k; i++) //revere links (k-1) for groups of size k
            {
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
            prev=cur; //to point to the current pointer
            count=count-k; 
        }
        
        return dummy->next;
    }
};
//TC: O(n/k) [traverse through list n but reversing only for groups of size k]
//SC: O(1)