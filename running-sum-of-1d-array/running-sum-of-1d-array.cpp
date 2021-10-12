class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        for(int i=1; i<nums.size();i++) //start from 1st index as 0th index should remain untouched
        {
            nums[i]+=nums[i-1]; //simpler way of writing nums[i]=nums[i]+nums[i-1]
            //here nums[i-1] becomes the previous index so we do 1,1+2,3+3,6+4 =>making the i'th index equal to the sum of current index value and the previous index value

        }
        return nums; //returns the array pointer
    }
};
