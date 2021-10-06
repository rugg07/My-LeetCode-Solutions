class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //using kadanes algorithm
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = std::max(0, maxCur += prices[i] - prices[i-1]); //if maxCur value becomes below 0 make it equal to 0
            maxSoFar = std::max(maxCur, maxSoFar); //finding the max element in chanigng maxCur
        }
        return maxSoFar; //the maxSoFar becomes the max profit as it becomes the highest value of cumulative sum (subtracting [i]-[i-1])
        
    }
};