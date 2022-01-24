/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        //we arent given the head node, so we cannot delete the node explicitly
        //but we can break its link so it appears to be delete.
        //use val since its the data variable used in struct ListNode
        
        node->val=node->next->val; //copy value of next ele into current node to be deleted
        node->next=node->next->next; //break its link to next ele and connect to ele after
    }
};
//TC: O(1) [just copying values and breaking the link, no traversal]
//SC: O(1)

//when given node can be tail node (last node) use a if statemnt to see if node->next=null then we just do node=null (the ele before it becomes the last ele then)