//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i = 0 ; i < n ; i++)
        {
            st.push(i);
        }
        
        while(st.size() != 1)
        {
            int top = st.top();
            st.pop();
            int secTop = st.top();
            st.pop();
            
            if(M[top][secTop] == 1)
            {
                st.push(secTop);
            }
            else
            {
                st.push(top);
            }
        }
        
        int left = st.top();
        
        bool rowCheck = false;
        int zeroCount = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(M[left][i] == 0)
            {
                zeroCount++;
            }
        }
        
        if(zeroCount == n)
            rowCheck = true;
            
        bool colCheck = true;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(M[i][left] != 1 && i != left)
            {
                colCheck = false;
            }
        }
        
        if(rowCheck && colCheck)
            return left;
        
        else
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
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends