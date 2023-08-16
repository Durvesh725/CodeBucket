//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> count;
		    queue<char> q;
		    string ans = "";
		    //traverse the string
		    for(int i = 0; i < A.length(); i++){
		        char ch = A[i];
		        //1. store each char count
		        count[ch]++;
		        
		        //2. push that char in the queue
		        q.push(ch);
		        
		        //3. check whether it is repeating ele
		        while(!q.empty()){
		            //repeating
		            if(count[q.front()] > 1){
		                q.pop();
		            }
		            else{
		                //non repeating
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        //4. '#' Case
		        if(q.empty())
		            ans.push_back('#');
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends