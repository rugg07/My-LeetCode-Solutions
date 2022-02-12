class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //BRUTE FORCE: normal traversal
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==target)
                return i;
        }
        return -1; //if target not found 
    }
};
//TC: O(n) [traverse arr]
//SC: O(1)