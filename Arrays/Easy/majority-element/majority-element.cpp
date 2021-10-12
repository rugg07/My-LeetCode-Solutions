class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_index=0; //the first element index
        int count=1; // since we take first ele as ME then count becomes 1
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[maj_index]==nums[i]) //when its the same major element
            {
                count++;
            }
            else //when its a different ele
            {
                count--;
            }
            if(count==0) //when count becomes 0 we make the current ele as ME and make count as 1 same as we did in the begining 
            {
                maj_index=i;
                count=1;
            }
        }
        return nums[maj_index]; //return the value 
    }
};