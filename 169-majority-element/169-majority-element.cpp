class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Optimal: (MOORES VOTING ALGORITHM)
        
        int maj_index=0; //the first element acts as index of major ele
        int count=0; // since we take first ele as Major ele then count becomes 1
        
        for(int i=0; i<nums.size(); i++)
        {
            //when count=0 we make the new ele as major ele 
            if(count==0) 
            {
                maj_index=i;
            }
            
            if(nums[maj_index]==nums[i]) //when ele in arr is same as major element
            {
                count++;
            }
            
            else //when its a different ele
            {
                count--;
            }
        }
        return nums[maj_index]; //return the value 
    }
};
//TC: O(n) [Traversing array once]
//SC: O(1)
