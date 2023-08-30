//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> s;
        
        for(int i = 0 ; i < x.length() ; i++)
        {
            char ch = x[i];
            
            if(ch=='{' || ch=='(' || ch=='[')
            s.push(ch);
            
            else
            {
                if(s.empty())
                return 0;
                
                else
                {
                    char t = s.top();
                    if((t == '{' && ch == '}') || (t == '(' && ch == ')') || (t =='[' && ch == ']'))
                    {
                        s.pop();
                    }
                    else
                    return 0;
                }
                
            }
        }
        
        if(s.empty())
        return true;
        else
        return false;
        
        
        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends