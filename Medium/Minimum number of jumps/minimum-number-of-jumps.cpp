//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n)
    {
        if (n <= 1) 
        {
            return 0;  // No jumps needed if there's only one element or none
        }
        
        if (arr[0] == 0) 
        {
            return -1;  // Cannot move from the starting position
        }

        int jumps = 1;  
        int farthest = arr[0];  
        int currentEnd = arr[0];  
        
        for (int i = 1; i < n; i++) 
        {
            if (i == n - 1) 
            {
                return jumps; 
            }
            
            farthest = max(farthest, i + arr[i]);
            
            if (i == currentEnd) 
            {
                jumps++;
                
                if (i >= farthest) 
                {
                    return -1;  
                }
                
                currentEnd = farthest;
            }
        }

        return -1; 
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends