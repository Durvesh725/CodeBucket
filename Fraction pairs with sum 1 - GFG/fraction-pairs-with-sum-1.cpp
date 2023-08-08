//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        //map to store fractions along with their frequencies
        map<pair<int,int>, int> fre;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            //get fraction in its simplest form
            int gcd = __gcd(numerator[i], denominator[i]);
            //get new num and deno
            numerator[i] /= gcd;
            denominator[i] /= gcd;
            int a, b;
            a = numerator[i];
            b = denominator[i];
            
            //check another fraction
            int c = b - a;
            
            //now check if the new pair (key) exists in a map
            if(fre.count({c,b}))
                //if yes, then only add its frequency count in the final ans count;
                ans+=fre[{c, b}];
            
            //increment frequency and store ele
            ++fre[{numerator[i], denominator[i]}];
        }
        return ans;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends