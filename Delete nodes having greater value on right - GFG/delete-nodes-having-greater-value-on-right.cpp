//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        while(curr){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    public:
    Node *compute(Node *head)
    {
        //1.reverse linked list
        Node* rev1Head = reverse(head);   
        Node* rev2Head = rev1Head;
        Node* prev = rev1Head;
        Node* forward = rev1Head -> next;
        //delete nodes having greater value on right
        int maxi = prev -> data;
        while(forward){
            if(forward -> data >= prev -> data){
                maxi = forward -> data;
                prev = forward;
                forward = prev -> next;
            }
            else{
                prev -> next = forward -> next;
                forward = prev -> next;
            }
        }
        
        //reverse the resultant linked list
        rev1Head = reverse(rev2Head);
        return rev1Head;
    }
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends