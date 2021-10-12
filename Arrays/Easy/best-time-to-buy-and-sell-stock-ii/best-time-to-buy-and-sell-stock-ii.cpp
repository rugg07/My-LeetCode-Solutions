class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur=0;
        for(int i=1;i<prices.size();i++)
        {
            //Kadanes algorithm implementation
            if(prices[i]>prices[i-1]) //as long as the consecutive element is more in value than the previous 
                maxCur+=prices[i]-prices[i-1]; //sum the difference of all transactions
        }
        return maxCur; //if the condition in the loop wont pass it automatically return 0
    }
};