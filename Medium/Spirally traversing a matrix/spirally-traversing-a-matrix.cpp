//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> ans;
        int srow = 0;
        int lrow = r - 1;
        int scol = 0;
        int lcol = c - 1;
        
        int count = 0;
        int total = r * c;
        
        while(count < total)
        {
            for(int i = scol ; i <= lcol && count < total ; i++)
            {
                ans.push_back(matrix[srow][i]);
                count++;
            }
            srow++;
            
            for(int i = srow ; i <= lrow && count < total ; i++)
            {
                ans.push_back(matrix[i][lcol]);
                count++;
            }
            lcol--;
            
            for(int i = lcol ; i >= scol && count < total ; i--)
            {
                ans.push_back(matrix[lrow][i]);
                count++;
            }
            lrow--;
            
            for(int i = lrow ; i >= srow && count < total ; i--)
            {
                ans.push_back(matrix[i][scol]);
                count++;
            }
            scol++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends