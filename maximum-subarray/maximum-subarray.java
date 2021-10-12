class Solution {
    public int maxSubArray(int[] nums) { //Kadane's Algorithm
        int maxSum = nums[0]; //To find the largest sum we equate it to the first element
        int currSum = 0; //and make the sum of the array in the begining as 0

    for (int i=0;i<nums.length;i++) //traverse array
    {
        if (currSum < 0) 
        {
            currSum = 0; //so that currSum value always stays at min 0
        }
        currSum += nums[i]; //find total sum of the array
        maxSum = Math.max(maxSum, currSum); //during this also find the max between currSum and maxSum 
        //if maxSum<currSum then maxSum gets the value of currSum 
    }

    return maxSum; //the maximum subbarray sum possible
    }
}