//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        vector<int> ans;
        unordered_map<int, int> count;
        
        for(int i = 0 ; i < n ; i++)
        {
            count[arr[i]]++;
        }
        
        for(auto i : count)
        {
            if(i.second > 1)
            {
                ans.push_back(i.first);
            }
        }
        
        if(ans.empty())
        {
            ans.push_back(-1);
        }
        
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends