class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //find total sum until nth element , if number of elements is 3 find sum till 3
        //Given that the array will be in range of [0,n] and missing number is between it
     int sum = 0;
        for(int i=1;i<=nums.size(); i++)
        {
            sum+=i;
        }
        
    //traverse through array and keep subtracting from sum. Remaining number is the missing number
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
        }
        return sum;
    }
};