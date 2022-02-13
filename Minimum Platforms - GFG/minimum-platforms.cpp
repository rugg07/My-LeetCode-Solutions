// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	//2-pointer - Greedy approach
    	
    	//sort using n since arr.begin(), arr.end() doesnt work
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int platform=1; //min of 1 platform will be required always 
    	int result= 0;  //store max no of platform
    	
    	int i=1; //i=1 (1st index) since we min req platform=1 for 0th train 
    	int j=0; //for dep
    	
    	//traverse both arr
    	while(i<n && j<n)
    	{
    	    //if departure time is more than or = arrival time of next train 
    	    //this means we will require an additional platform
    	    if(arr[i]<=dep[j])
    	   {
    	        platform++;
    	        i++;
    	   }
    	   
    	   //if arrival time is more than departure time 
    	   //it means new train can come on existing platform,
    	   //Eg: arr=12:01pm but dept=11:00am so we have free platform
    	   else if(arr[i]>dep[j])
    	   {
    	       platform--;
    	       j++;
    	   }
    	   
    	   //if platform is reduced we keep track of max platform 
    	   if(platform>result)
    	       result=platform;
    	
    	}
    	return result; 
    }
};
//TC: O(nlogn) [traverse arr * sorting array]
//SC: O(1)

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends