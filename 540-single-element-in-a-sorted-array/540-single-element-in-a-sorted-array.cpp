class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //OPTIMAL:  
        int low = 0, high = nums.size() - 2; 
        while(low <= high) {
            int mid = (low + high)/2; 
            if(nums[mid] == nums[mid^1]) {
                low = mid + 1; 
            } 
            else {
                high = mid - 1; 
            }
        }
        return nums[low]; 
    }
};
/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //BRUTE FORCE: xor ^ 
        
        int res=0;
        //xor of values repeated twice is 0, the value stored is of the value present once
        for(int i=0; i<nums.size(); i++)
            res=res^nums[i];
        
        return res;
    }
};
//TC: O(n) [n ele]
//SC: O(1)
*/