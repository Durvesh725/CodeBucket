/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
            
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* rightptr = nullptr;
            int s = q.size();
            for(int i = 0; i < s; i++){
                Node* element = q.front();
                q.pop();
                element -> next = rightptr;
                rightptr = element;
                
                if(element -> right){
                    q.push(element -> right);
                    q.push(element -> left);
                }    
            }
        }

        return root;
    }
};