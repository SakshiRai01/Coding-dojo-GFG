//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // vector<long long> ans(n);
        // ans[n-1] = -1;
        // stack<long long> s;
        // s.push(arr[n-1]);

        // for(int i = n-2 ; i >= 0 ; i--)
        // {
        //     int curr = arr[i];
        //     while(!s.empty() && curr >= s.top())
        //     {
        //         s.pop();
        //     }
            
        //     if(s.empty())
        //         ans[i] = -1;
            
        //     else
        //         ans[i] = s.top();
                
        //     s.push(curr);
        // }

        // return ans;
        
        
        stack<long long>st;
        vector<long long>ans(n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=arr[i]) 
            st.pop();
            // if(i<n)
            {
                if(!st.empty()) ans[i]=st.top();
                else ans[i]=-1;
            }
            st.push(arr[i]);
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends