class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        //BRUTE FORCE
        
        int count=0;
        
        for(int i=0; i<nums.size();i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
              if(nums[i]==nums[j])
                count++;
            }    
        }
        return count;
    }
};
//TC: O(n^2) [traversing array for each ele from i and j=i+1]
//SC: O(1)