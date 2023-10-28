//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    unsigned int countSetBits(unsigned int x)
    {
        unsigned int count = 0;
        while (x) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
    
    // A function to return ceiling of log x
    // in base 2. For example, it returns 3
    // for 8 and 4 for 9.
    int ceilLog2(int x)
    {
        int count = 0;
        x--;
        while (x > 0) {
            x = x >> 1;
            count++;
        }
        return count;
    }
    
public:
	int is_bleak(int n)
	{
	    for (int x = n - ceilLog2(n); x < n; x++)
        if (x + countSetBits(x) == n)
            return false;
        return true;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends