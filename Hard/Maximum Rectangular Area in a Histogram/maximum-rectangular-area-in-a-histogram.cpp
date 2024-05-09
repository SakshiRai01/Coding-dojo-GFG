//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    //Function to find largest rectangular area possible in a given histogram.
    vector<int> prevSmall(long long arr[] , int n)
    {
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            while(st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> nextSmall(long long arr[] , int n)
    {
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            while(st.top() != -1 && arr[st.top()] >= arr[i])
            {    
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    public:
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> prev(n);
        vector<int> next(n);
        
        prev = prevSmall(arr , n);
        next = nextSmall(arr , n);
        
        long long area = INT_MIN;
        
        for(int i = 0 ; i < n ; i++)
        {
            long long height = arr[i];
            if(next[i] == -1)
            {
                next[i] =  n;
            }
            
            long long breadth = next[i] - prev[i] - 1;
            long long newArea = height * breadth;
            
            area = max( area , newArea );
        }
        
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends