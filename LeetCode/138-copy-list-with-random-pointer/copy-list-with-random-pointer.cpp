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
        Node* temp = head;

        // copy nodes in between
        while(temp){
            Node* copyNode = new Node(temp -> val);
            copyNode -> next = temp -> next;
            temp -> next = copyNode;
            temp = copyNode -> next;    
        }

        // connecting random pointers
        temp = head;
        while(temp){
            Node* copyNode = temp -> next;
            if(temp -> random != NULL)
                copyNode -> random = temp -> random -> next;
            else
                copyNode -> random = NULL;

            temp = temp -> next -> next;   
        }

        // join next pointers of copied Linked list - extract copied from original
        Node* dummy = new Node(-1);
        Node* res = dummy;

        temp = head;
        while(temp != NULL){
            res -> next = temp -> next;
            temp -> next = temp -> next -> next;

            temp = temp -> next;
            res = res -> next;
        }

        return dummy -> next;
    }
};