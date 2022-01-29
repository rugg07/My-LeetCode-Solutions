/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*class Solution {
public:
    bool hasCycle(ListNode *head) {
        //OPTIMAL: Two-pointer approach (slow & fast)
        
       
    }
};
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //BRUTE FORCE: using hashMap
        
        //no ele in the list
        if(head==NULL)
            return false;
        
        unordered_map<ListNode*, int> map; //store the node and count
        
        ListNode * curr=head; //pointer for the list
        
        while(curr!=NULL)
        {
            map[curr]++; //update count of the node in hashmap
            
            if(map[curr]>1) //if count>1 means node is repeating
                return true;
            
            curr=curr->next;//go to next node
        }
        return false;
    }
};
//TC: O(n) [traverse through list]
//SC: O(n) [hashMap to store all n ele]
