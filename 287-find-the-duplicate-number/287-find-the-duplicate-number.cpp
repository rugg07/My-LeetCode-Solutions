class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       //Linked List Cycle Method
        
        //initialize both pointers to first element
        int slow = nums[0];
        int fast = nums[0];
        
        //keep incrementing slow by one step and fast by 2 steps. Do till slow and fast don't meet.
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        //Now make fast to first element again and increment slow and fast by one step now
        
        fast = nums[0];
        
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        //since nums and fast met and both have the value of duplicate element
        return slow;
    }
};

//TC:O(n) traversing only once
//SC:O(1) as constant space is only used.

/*----------------------------------------------------------------------------------------------*/
/*
 
*/