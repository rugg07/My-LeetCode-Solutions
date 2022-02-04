class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //BRUTE FORCE: traversing array
        
        int count=0; //current count
        int maxCount=0; //maximum count
        
        if(nums.size()==0) //if arr is empty
            return 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                count++;
                maxCount = max (maxCount, count); //keep track of max count
            }
            else
            {
                count=0;
            }
        }
        return maxCount;
    }
};
//TC: O(n) [traverse arr of size n]
//SC: O(1)