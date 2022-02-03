// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *mergeLists(Node *a, Node *b)
{
    //make 2 pointers both pointing to dummy node with value null   
    Node *dummy = new Node(0);  
    Node *temp=dummy;
    
    //go till end of each list
    while(a!=NULL && b!=NULL)
    {
        //use bottom since final list should be using bottom
        
        if(a->data<b->data)
        {
            dummy->bottom=a; //next node points to list a
            dummy=dummy->bottom;//go to next node in list starting from dummy
            a=a->bottom; //go to next node in list a
        }
        else
        {
            dummy->bottom=b; //next node points to list b
            dummy=dummy->bottom;//go to next node in list starting from dummy
            b=b->bottom; //go to next node in list a
        }
    }
    
    //check if there is any remaining nodes in either list
    if(a!=NULL)
        dummy->bottom=a;
    else
        dummy->bottom=b;
    
    //since first node is NULL our head node starts from 2 node. so we do this
    return temp->bottom;
}
    
Node *flatten(Node *root)
{
   // OPTIMAL: USING RECURSION
   if(root==NULL || root->next==NULL) //if root has 0/1 node we return it directly
    return root;
    
   root->next = flatten(root->next); //go to next list on right side 
   root = mergeLists (root, root->next); //merge the current list and next list
   
   return root; //after merging all lists return the final root
}

//TC: O(m*n) [traversing all nodes (in ->bottom & ->next)]
//SC: O(1)

