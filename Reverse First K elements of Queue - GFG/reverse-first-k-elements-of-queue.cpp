//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    //reverse K elements
    for(int i = 0; i < k; i++){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }
    
    //add reversed K elements in the queue
    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }
    
    //reverse remaning ele
    int remain = q.size() - k;
    while(remain--){
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
    return q;
}