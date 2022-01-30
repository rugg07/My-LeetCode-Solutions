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