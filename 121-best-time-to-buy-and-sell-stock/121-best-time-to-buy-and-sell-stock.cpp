class Solution {
public:
    int maxProfit(vector<int>& prices) {
     //using kadanes algorithm
        
        
        int maxCur = 0;//max Sum of the iteration
        int maxSoFar = 0; //max Sum till that iteration
        
        //we start from i=1 so that we can keep subtracting the value before it and store in maxCur
        for(int i = 1; i < prices.size(); i++)
        {
           maxCur = maxCur + (prices[i]-prices[i-1]);
            
            //if maxCur value becomes below 0 make it equal to 0. 
            //Because if <0 then maxSoFar remains same always
            if(maxCur<0)
                maxCur=0;
           
            //To keep Track of max value between the two
            maxSoFar = max(maxCur, maxSoFar); 
            
        }
        
        //the maxSoFar becomes the max profit as it becomes the highest cummulative sum 
        return maxSoFar; 
        
    }
};
//TC: O(n) [1 loop to iterate]
//SC: O(1)

/*--------------------------------------------------------------------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //BRUTE FORCE:
        
        //one to store sum for the iteration, other stores max sum till that iteration is executed
       int sum=0, max_sum=0;
        
        //if no elements or if only one ele is present we return 0
        //1 ele present means we cant buy and sell on same day
        if(prices.size()==0 || prices.size()==1)
            return 0;
        
    //traverse from each element and see if any element on right is greater (prices[i]<prices[j])
        for(int i=0; i<prices.size(); i++)
        {
            for(int j=i+1; j<prices.size(); j++)
            {
                if(prices[i]<prices[j])
                {
                    sum=prices[j]-prices[i];
            //we do max_sum later because otherwise maximum of both sum may not be stored properly
                    max_sum = max(max_sum, sum);
                     
                }
            }
        }
        return max_sum;
    }
};
TC: O(n^2)[iterating using i and j]
SC: O(1)

*/