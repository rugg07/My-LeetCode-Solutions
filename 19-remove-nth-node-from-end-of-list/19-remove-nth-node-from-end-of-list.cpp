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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //OPTIMAL
        ListNode* dummy = new ListNode(); //create dummy node
        
        dummy->next=head; //dummy node points to head
        
        //make slow & fast pointer both should point to dummy node
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        //traverse list with fast until it reaches n (node to be deleted)
        for(int i=1; i<=n; i++)
        {
            fast=fast->next;
        }
        
        //If fast would have reached NULL this means the node to be deleted 
        //is equal to the number of nodes in the linked list.   
        if(fast==NULL)
        {
            ListNode* node = head;
            head=head->next;
            delete node;
            return head;
        }
        
        //move fast & slow by 1 step until next ele of fast!=NULL                                
        //slow pointer is standing one node before the node to be deleted.
        while(fast->next!=NULL) 
        {
            slow=slow->next; 
            fast=fast->next;
        }
        
    slow->next=slow->next->next;//break link to next ele and make it join the ele after
    
 //since dummy itself is NULL we need to print from head onwards and done above dummy=head 
    return dummy->next; 
    }
};
//TC: O(n) [traverse array with fast pointer till n and after n [0..n][n+1..last ele]]
//SC: O(1)
/* ---------------------------------------------------------------------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        //BRUTE FORCE: 
        ListNode* current = head; //start from head node
        int count=1;
        int iteration=1;
        
        while(current->next!=NULL) //count the length of the list
        {
            current=current->next;
            count++;
        }

        if(head==NULL) //no ele in list
            return head;
        
         if(count==n) //if we need to delete 1st ele i.e the head
        {
             ListNode *node=head; //make new pointer and point to head
             head=head->next; //make the next ele after head as head
             delete node; //delete original head
             return head; 
        } 
        
        //no need to explicilty delete until told to, doing head->next removes main head also.
        
         count=count-n; //decrease count to find ele after iteration needed to be deleted
        
         //both pointers start at head 
         ListNode* newCurrent = head; 
         ListNode* temp = head;
        
        while(iteration!=count) //go until ele before the one being deleted
        {
            iteration++; 
            newCurrent=newCurrent->next; 
        }
        
        //keep this outside while loop because its edge case.
        //if ele to be deleted is last ele then newCurrent would end up pointing to NULL in loop
        
        temp=newCurrent->next; //we need to delete next ele after iteration=count
        
        //break the link to next ele and join to the ele after since it will be count-n+1 pos
        newCurrent->next=newCurrent->next->next;
        delete temp;  
        return head; //told to return head
    }
};
//TC: O(n) + O(n) = O(2n) [traverse to count list length + traverse to delete nth node]
//SC: O(1)
*/
