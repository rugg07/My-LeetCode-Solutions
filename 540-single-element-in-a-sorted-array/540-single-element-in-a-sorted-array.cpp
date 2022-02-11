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