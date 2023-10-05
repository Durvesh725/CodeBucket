//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long upto(string s, int k){
        int l = 0, r = 0;
        //cnt is used to keep the track of distinct substrings
        int cnt = 0;
        long long ans = 0;
        //mapping between each char and its frequecy
        vector<int> mp(26, 0);
        
        while(r < s.length()){
            //1. add char and its fre in map
            mp[s[r] - 'a']++;    
            //2. check for distinct count
            if(mp[s[r] - 'a'] == 1)
                cnt++;
            
            while(cnt > k){
                mp[s[l] - 'a']--;
                //if that element doesnt exist, reduce the distinct count
                if(mp[s[l] - 'a'] <= 0){
                    cnt--;
                }
                l++;
            }
            ans = ans + (r-l)+1;
            r++;
        }
        return ans;
    }
    
    long long int substrCount (string s, int k) {
    	return upto(s, k) - upto(s, k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends