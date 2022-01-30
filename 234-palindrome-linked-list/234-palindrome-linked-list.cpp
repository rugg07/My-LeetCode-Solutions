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
    bool isPalindrome(ListNode* head) {
       //OPTIMAL: (find middle + reverse right half of list + compare left & right half)
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        if(head==NULL || head->next==NULL)//no ele or only 1 ele in list so its palindrome
            return true;
        
        while(fast->next && fast->next->next) // finding middle of linked list 
        {   
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *curr=slow->next; //points to the node after middle node
        
        ListNode *prev=NULL; //make new node to store previous values
        ListNode *temp; //points to prev (new node) that stores previous value
        
        while(curr!=NULL)//reversing the right half of the list that is after the mid node 
        {   
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=prev;  // joining the reversed linked list after the middle node
          
        ListNode *start = head;//point to 1st node
        ListNode *mid = slow->next; //point to mid's next node (mid+1)
        
        while(mid!=NULL) // valued being checked here
        { 
            //check from 1st till mid node WITH mid->next node to end
            if(start->val!=mid->val)
                return false;
            
            start=start->next;
            mid=mid->next;
        }
        return true;
       
    }
};
//TC: O(n/2)+ O(n/2) + O(n/2) = O(3n/2) = O(n)
//[find mid of list + reverse right half of list + compare left & right half]
//SC: O(1)
/*---------------------------------------------------------------------------------------
class Solution {
public:
    bool isPalindrome(ListNode* head) {
       //BRUTE FORCE: Using vector array
        
        vector<ListNode*> arr;//vector array to store all nodes
        
        int i=0;
        
        while(head!=NULL)
        {
            arr.push_back(head);//insert all nodes into array
            head=head->next;
        }
        int arrlen = arr.size()-1; //last index of array
        
        //loop to see if palindrome exists
        for(int j=0; j<=arrlen/2; j++)
        {
            //do -> val to acess the values of the nodes stored in the array
            if(arr[j]->val!=arr[arrlen-j]->val)
                return false;
        }
        return true; //palindrome exists
    }
};
//TC: O(n)+O(n) = O(2n) [loop to store nodes + loop to see if palindrome exists]
//SC: O(n) [array to store the nodes]
*/