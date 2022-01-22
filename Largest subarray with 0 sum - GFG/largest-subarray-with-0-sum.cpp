// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> hash; //store the prefixsum and index
        
        int sum=0;
        int maxLength=0;
        
        for(int i=0; i<n; i++)
        {
            sum+=A[i];
            if(sum==0)
                maxLength=i+1; //till that pos we get 0, i+1 since we start from i=0 
            
            else
            {
                if(hash.find(sum)!=hash.end()) //if sum is present in hashmap
                   { //index of curr pointer in arr - previously stored sum index
                       maxLength = max (maxLength, i-hash[sum]); 
                   }
                   else
                   {//when not found store the sum with current arr index  
                    hash[sum]=i;
                   }
                }
        }
        return maxLength;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends