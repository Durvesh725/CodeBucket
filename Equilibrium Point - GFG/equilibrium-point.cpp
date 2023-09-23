//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        int s = 0;
        int e = n-1;
        long long sumS = a[s];
        long long sumE = a[e];
        
        while(s < e){
            if(sumS < sumE){
                s++;
                // cout << "s: " << s << endl;
                sumS += a[s];
            }
            else{
                e--;
                // cout << "e: " << e << endl;
                sumE += a[e];
            }
        }
        if(sumS == sumE)
            return e+1;
        else
            return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends