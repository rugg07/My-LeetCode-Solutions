class Solution {
public:
    int climbStairs(int n) 
    {   //It is Fibonacci sequence where numbers start from 1 instead of 0,1(first 2 numbers of fibonacci series) so we get 1,2,3,5,8,13,... for steps 1,2,3,4,5,6,...
        
        if(n==1) //if only one step needs to be taken then by theory we can only take one step
            return 1;
        
        int a=1; //step 1
        int b=1; //step 2
        int ans;
        for(int i=1;i<n;i++) 
        {
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
        
        //we done check if n==0 because given constraint is n has to be between 1 to 45
        
    }
};