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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy= new ListNode(); //make a dummy node to act as head node
        ListNode* temp=dummy; //points to the dummy node 
        
        int carry=0; 
        
    //iterate until it points to null not the ->next being null, so we can sum till end
        
        while(l1!=NULL || l2!=NULL || carry) //stop if carry becomes 0 in the end as well
        {
            int sum=0; //sum has to be 0 for each iteration
           
            if(l1!=NULL) 
            {
               sum+=l1->val; //add the value of node in list 1 and iterate to next ele
               l1=l1->next;
            }
           
            if(l2!=NULL)
            {
               sum+=l2->val; //add the value of node in list 2 and iterate to next ele
               l2=l2->next;
            }
            
            sum+=carry; //add sum and carry
            carry=sum/10; // sum/10 will give carry if possible
            
            //make new node on each iteration to store value of sum
            //we do %10 to store the first/unit's digit only everytime we make new node, 
            //carry will store the ten's digit 
            ListNode* node = new ListNode(sum%10); 
            
            //temp acts as the pointer going over every new "node" formed on iteration
            
            temp->next=node; //next ele should point to new node formed
            temp=temp->next; //go to next ele 
        }
        return dummy->next; //since we made dummy->next to be head node we return it
    }
};
//TC: O(max(n1,n2)) [because depends on max length of list 1 or list 2]
//SC: O(n) [creating new linked list]
