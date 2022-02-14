class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxresult=0; //store max result of all customers
        
        for(int i=0; i<accounts.size(); i++)
        {
            int result=0; //has to be 0 for each customer (i), so initialized in forloop
            
            for(int j=0; j<accounts[i].size();j++)
            {
                //find total of that customer & also keep track of max for each iteration
                result+=accounts[i][j]; 
                maxresult=max(maxresult,result);
            }
            //can also find max after finding total of each customer by keeping here
        }
        return maxresult;
    }
};
//TC: O(m*n) [since its a 2D matrix]
//SC: O(1)