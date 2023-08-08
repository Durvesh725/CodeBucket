//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    private:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    //reverse nodes after middle ele
    Node* reverse(Node* temp){
        Node* curr = temp;
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
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head -> next == NULL){
            return 1;
        }
        
        //1. get middle element
        Node* middle = getMid(head);
        //join reversed linked list to next of middle ele
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //3. Compare two havles
        Node* head1 = head;
        Node* head2 = middle -> next;
        while(head2){
            if(head1 -> data != head2 -> data){
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return 1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends