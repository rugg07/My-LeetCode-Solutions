/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //OPTIMAL: 
        
          Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          // A->A'->B->B'->C->C'
          while (iter != NULL) 
          {
            front = iter->next;
              
            //store the value into the copy
            Node *copy = new Node(iter->val);
            iter->next = copy; //original node points to copy node
            copy->next = front; //clone node point to next node in original list

            iter = front; 
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) 
          {
            //the random pointer in clone points to the next node for random in org. node
            //iter->next (clone node) iter->random->next(next node that random points too)
            if (iter->random != NULL) 
              iter->next->random = iter->random->next; 
        
            //every second node is original lists node so we do next->next
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
        
          Node *pseudoHead = new Node(0); //new node
          Node *copy = pseudoHead;

          //we are skipping/breaking links of org. node to clone nodes list and vice versa 
          while (iter != NULL) 
          {
            front = iter->next->next; //front points to org. nodes

            // extract the copy
            copy->next = iter->next; //A->A’->B->B’, A’->next will point to B’. i.e A’->B’

            // restore the original list                
          //A->A’->B->B’ so here A->next points to front which will be A->next->next i.e B
            iter->next = front; 
              
            copy = copy -> next; //go to next node in clone list 
            iter = front; //go to next node in org list.
          }

          return pseudoHead->next; //since first node is null, 2nd node is head node
    }
};
//TC:O(n)+O(n)+O(n)=O(3n)=O(n)[assign val + assign random + segregate org and cloned list]
//SC:O(1) [since we need to return new list, we dont take its SC]
/*----------------------------------------------------------------------------------------
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //BRUTE FORCE: using hashMap 
        
       // this map points to the clone of the original node
        map<Node*,Node*> mp;
        
        Node* temp=head;
        
        // 1st Pass - Creation of Nodes and no wiring
        while(temp!=NULL)
        {
            // Pointing the original node to its clone node
            // Now I can access the clone node in O(1)
            mp[temp] = new Node(temp->val);
            temp=temp->next;
            
        }
        
        // 2nd pass - Filling the next and random pointers
        temp=head;
        
        while(temp!=NULL)
        {
            // mp[ptr] is the clone node and its next is the next original
            // node's clone node. 
            // mp[ptr->next] refers to the clone node of ptr->next;
            mp[temp]->next= mp[temp->next]; 
            
            // similar thing for the random pointer
            mp[temp]->random=mp[temp->random];
            
            temp=temp->next;
        }
        
        return mp[head];
    }
};
//TC: O(N) [traversing list]
//SC: O(N) [hashMap]
*/