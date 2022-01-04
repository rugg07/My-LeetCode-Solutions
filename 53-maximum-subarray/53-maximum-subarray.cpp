class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
//Optimal: Kadane's Algorithm
        
        //max_sum should point to first element
        int max_sum = nums[0];
        //start with curr_sum as 0 because in the process also sum should'nt be < 0.
        int current_sum = 0;
        
        //each iteration keep adding sum and updating max
        for(int i=0; i<nums.size(); i++)
        {
            current_sum+=nums[i];
            max_sum = max(max_sum,current_sum);
        //if sum becomes < 0 make it 0 because having -ve sum doesnt help in getting max subarray
            if(current_sum<0)
            {
                current_sum=0;
            }
        }
        
        //max_sum is the maximum subarray
        return max_sum;
    }
};