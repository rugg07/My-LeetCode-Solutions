class Solution {
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
         //Better: Recursion + DP
        
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
//TC:O(n*m) [At max there will be n*m states, after that there wont be any further recursive calls]
//SC:O(n*m) [initializing a dynamic array of m*n]

/*-------------------------------------------------------------------------------------------------class Solution {
public:
    int countPaths(int i, int j, int m, int n){
         //Brute Force: use Recursion
        
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
//TC: O(exponential) [it can take either path i.e tries all possible combinations]
//SC: O(exponential) [uses stacks based in recursion]
*/