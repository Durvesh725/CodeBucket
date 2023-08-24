//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //1. if neg sign exists, remove it and add it later
       bool neg = 0;
       
       if(s1[0] == '-'){
           neg ^= 1;    //sets value of neg to 1
           s1 = s1.substr(1);
       }
       
       if(s2[0] == '-'){
           neg ^= 1;    //sets value of neg to 1
           s2 = s2.substr(1);
       }
       
       
       //2. rev the strings
       reverse(s1.begin(), s1.end());
       reverse(s2.begin(), s2.end());
       
       //3. get length of strings
       int n = s1.length();
       int m = s2.length();
       
       vector<int> ans(n+m, 0);
       
       //4. for loops for multiplication
       //1st for loop for second no.
       for(int i = 0; i < m; i++){
           //index will also act as position
           int pos = i;
           int x = s2[i] - '0';
           //2nd for loop for first no
           for(int j = 0; j < n; j++){
               int y = s1[j] - '0';
               
               ans[pos] += x * y;
               //if it is a two digit multiplication
               if(ans[pos] > 9){
                   ans[pos + 1] += ans[pos]/10; //get carry(i.e left digit)
                   ans[pos] = ans[pos] % 10;    //extract right digit
               }
               ++pos;
           }
       }
       
       bool found = 0;
       string res = "";
       
       //traverse the vector in reverse direction
       for(int i = ans.size()-1; i >= 0; i--){
           if(ans[i] > 0){
               found = 1;
           }
           
           if(found){
               res += (char)(ans[i] + '0');
           }
       }
       
       if(neg)
            res = '-' + res;
        
        return res;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends