//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int zero = 0 , one = 0 , two = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] == 0)
            {
                zero++;
            }
            else if(arr[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        
        int i = 0;
        while(zero--)
        {
            arr[i++] = 0;
        }
        while(one--)
        {
            arr[i++] = 1;
        }
        while(two--)
        {
            arr[i++] = 2;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends