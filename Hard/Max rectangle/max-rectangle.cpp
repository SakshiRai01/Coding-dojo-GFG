//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    
    private:
    vector<int> prev(int* arr , int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        
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
    
    vector<int> next(int* arr , int n)
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
    
    int maxArea(int *arr , int n)
    {
        vector<int> ne(n);
        vector<int> pe(n);
        
        int area = INT_MIN;
        
        ne = next(arr , n);
        pe = prev(arr , n);
        
        for(int i = 0 ; i < n ; i++)
        {
            int length = arr[i];
            if(ne[i] == -1)
            {
                ne[i] = n;
            }
            
            int breadth = ne[i] - pe[i] - 1;
            
            int newArea = breadth * length;
            area = max(area , newArea);
        }
        
        return area;
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) 
    {
        int area = maxArea(M[0] , m);
        
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            area = max(area , maxArea(M[i] , m));
        }
        
        return area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends