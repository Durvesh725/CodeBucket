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
        unordered_map<Node*, Node*> um;

        while(temp != NULL){
            Node* newNode = new Node(temp->val);
            um[temp] = newNode;
            temp = temp -> next;
        }      

        temp = head;
        while(temp != NULL){
            Node* copiedNode = um[temp];
            copiedNode -> next = um[temp -> next];
            copiedNode -> random = um[temp -> random];
            temp = temp -> next;
        }

        return um[head];
    }
};