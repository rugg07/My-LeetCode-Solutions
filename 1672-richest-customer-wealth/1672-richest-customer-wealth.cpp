class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxresult=0; //store max result of all customers
        
        for(int i=0; i<accounts.size(); i++)
        {
            int result=0; //has to be 0 for each customer (i), so initialized in forloop
            
            for(int j=0; j<accounts[i].size();j++)
            {
                //find total of each customer
                result+=accounts[i][j]; 
            }
            //update maxresult if the total has increased
            maxresult=max(maxresult,result);
        }
        return maxresult;
    }
};
//TC: O(m*n) [since its a 2D matrix]
//SC: O(1)