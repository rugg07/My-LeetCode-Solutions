class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //OPTIMAL:  modified binary search
        
        int low = 0;
        int high = nums.size() - 2; //2nd last ele
        
        //similar to binary search
        while(low <= high) {
            
            int mid = (low + high)/2; 
            
            if(nums[mid] == nums[mid^1]) //xor mid pos with 1
                low = mid + 1; //pattern in left half is wrong
            
            else 
                high = mid - 1; //patter in right half is wrong
        }
        return nums[low]; //ele that all pointers point too, (can be the last ele also)
    }
};

//TC: O(logn) [using modified binary search]
//SC: O(1)
/*----------------------------------------------------------------------------------------
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