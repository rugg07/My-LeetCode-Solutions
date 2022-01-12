class Solution {
public:
   //OPTIMAL: (COMBINATIONS)
    int uniquePaths(int m, int n) {
        
//we will always take RIGHT(m-1) steps and BOTTOM(n-1) steps to final index. TotalSteps=(m-1)+(n-1)
//total_steps acts as n (numerator) of nCr
       int total_steps=m+n-2;

//to find number of unique paths we can either take m-1 or n-1, since it always requires those many number of steps to reach final destination
        int r=m-1;
        
//total unique path would be m+n-2 C r  
        double res=1;
        
//we take only the last r number ele from total_steps. eg:from 10C3 we take 10*9*8/3*2*1(last3ele)
//here i acts as r! so we keep dividing by i, eg: 3! => 1*2*3
        for(int i=1;i<=r;i++)
        {
            res= res*(total_steps-r+i)/i;
        }
        return res;
    }
};
//TC: O(m-1) OR O(n-1) [depends on if you calc Combinations with m-1 or n-1]
//SC: O(1) 

/*-------------------------------------------------------------------------------------------------
class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
         //BETTER: [RECURSION + DP]
        
        //if it hits final index we return 1
        if(i==(m-1) || j==(n-1))
            return 1;
        //if index goes out of bound we return 0
        if(i>=m || j>=n)
            return 0;
       //if state has already been visited just return its dp table value directly
        if(dp[i][j]!=-1)
            return dp[i][j];
        //we calculate the path of both sides BOTTOM & RIGHT, store it for that index in dp table
        else 
            return dp[i][j]=countPaths(i+1,j,m,n,dp) + countPaths(i,j+1,m,n,dp); 
        //we need to pass m and n each time to use it for our if conditions
    }
    
    int uniquePaths(int m, int n) {
        //since we need to start from 0th index we make pass i,j as 0
       int i=0, j=0;
        //since we use DP we make a table and initialize values to -1
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return countPaths(i,j,m,n,dp);
    }
};
//TC:O(m*n) [At max there will be n*m states, after that there wont be any further recursive calls]
//SC:O(m*n)+O(m*n) [initializing a dynamic array of m*n + Recursive space of m*n]
  => O(m*n) aprox.
*/
/*-------------------------------------------------------------------------------------------------class Solution {
public:
    int countPaths(int i, int j, int m, int n){
         //BRUTE FORCE: [RECURSION]
        
        //if it hits final index we return 1
        if(i==(m-1) || j==(n-1))
            return 1;
        //if index goes out of bound we return 0
        if(i>=m || j>=n)
            return 0;
        //if neither happen we do recursion in countPath with 2 paths. BOTTOM=(i+1,j) RIGHT=(i,j+1)
        else 
            return countPaths(i+1,j,m,n) + countPaths(i,j+1,m,n); 
        //we need to pass m and n each time to use it for our if conditions
    }
    
    int uniquePaths(int m, int n) {
        //since we need to start from 0th index we make pass i,j as 0
       int i=0, j=0;
        return countPaths(i,j,m,n);
    }
};
//TC: O(2^(m+n)) [it can take either path i.e tries all possible combinations]
//SC: O(m+n) [uses stacks based in recursion so total would be the no. of rows and columns (m+n)]
*/