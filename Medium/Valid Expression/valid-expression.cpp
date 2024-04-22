//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
     stack<char>st;
    for(int i=0 ; i < s.length() ; i++) 
    {
        char curr = s[i];
        if(curr=='(' || curr=='{' || curr == '[') 
        {
            st.push(curr);
        }
        
        else 
        {
            if(!st.empty()) 
            {
                char top = st.top();
                if((top=='(' && curr ==')') || (top=='{' && curr =='}') || (top=='[' && curr ==']')){
                    st.pop();
                }
                else 
                {
                    return false;
                }
            }
            else 
            {
                return false;
            }
        }
        
    }
    if(st.empty()) 
    {
        return true;
    }
    return false;
}