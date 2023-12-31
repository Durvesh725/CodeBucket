//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data){
        Node* curr = head;
        //if no elements exists
        if(curr == NULL){
            Node* newNode = new Node(data);
            return newNode;
        }
        
        //head
        if(data < curr -> data){
            Node* newNode = new Node(data);
            newNode -> next = curr;
            return newNode;
        }
        
        //middle
        while(curr -> next){
            if(data < curr -> next -> data){
                Node* newNode = new Node(data);
                newNode -> next = curr -> next;
                curr -> next = newNode;
                return head;
            }
            curr = curr -> next;
        }
        
        //tail
        Node* newNode = new Node(data);
        curr -> next = newNode;
        return head;
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends