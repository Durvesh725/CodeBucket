//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    // 	long long sum = 0;
    // 	for(int i = 0; i < n-1; i++){
    // 	    for(int j = i+1; j < n; j++){
    // 	        sum += arr[i] ^ arr[j];
    // 	    }
    // 	}
    // 	return sum;
    long long sum = 0;
    for(int i = 0; i < 32; i++){
        long long zero_cnt = 0;
        long long one_cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j]%2 == 0)
                zero_cnt++;
            else
                one_cnt++;
                
            //as the last bit is processed
            arr[j] = arr[j]/2;
        }
        sum += one_cnt * zero_cnt * (1<<i);
        //1 << x means 1 * 2^0(likewise 2^1, 2^2), 
    }
    return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends