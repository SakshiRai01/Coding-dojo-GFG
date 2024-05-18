//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        int s = 0 , e = a.size() - 1;
        
        while(s < e)
        {
            int mid = s + (e-s)/2;
            
            if(a[mid] > a[mid + 1])
            {
                e = mid;
            }
            
            else
            s = mid + 1;
        }
        
        return a[e];
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
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends