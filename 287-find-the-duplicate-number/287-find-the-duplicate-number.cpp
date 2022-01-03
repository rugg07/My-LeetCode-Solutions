class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
 //Optimal Approach: Linked List Cycle Method
        
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
//Better Approach:
  int n = nums.size();
        
        //to initialize a dynamic array with all values 0
        int *frequency_arr = new int[n]{0};
        
//traverse original array and depending on the value add 1 to value present in index of freq arr
        for(int i=0; i<n ; i++)
        {
            frequency_arr[nums[i]]++;
        }

        //traverse new array and check if value>1. If true then its duplicate element
        for(int i=0; i<n ; i++)
        {
            if(frequency_arr[i]>1)
            {
                return i; //the index in frequency_arr is of the value in orginial array
            }
        }
        return -1;
    }
};

//TC: O(n)+O(n) [traverse org arr + traverse new arr]
//SC: O(n) [new arr]
*/
        
