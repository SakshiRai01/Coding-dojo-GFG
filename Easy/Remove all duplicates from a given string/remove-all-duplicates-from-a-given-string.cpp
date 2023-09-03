//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_set<char> s;
	    string ans ;
	    for(int i = 0 ; i < str.length() ; i++)
	    {
	       if(s.find(str[i]) == s.end())
	       { 
	           s.insert(str[i]);
	           ans += str[i];
	       }
	    }
	   
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends