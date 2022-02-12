class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //OPTIMAL: binary search in sorted parts of arr
    
        int low=0;
        int high=nums.size()-1;
        
        //perform binary search on array
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==target) //if we find value directly return index
                return mid;
        
            //incase array is rotated, array is still sorted partially in two parts
            //two parts are left part and right part 
            //Eg: [4,5,6,7,0,1,2], left=[4,5,6,7] right=[0,1,2]
            
            //left side is sorted 
            if(nums[low] <= nums[mid])
            {
            
                //it should appear in left half of arr behind mid 
                if(target >= nums[low] && target <= nums[mid]) 
                    high = mid - 1; 
                
                else //present in right half
                    low = mid + 1; 
                
            }
            
            //right side is sorted
            else //nums[low]>nums[mid]
            {  
                //it should appear in right half of arr after mid
                if(target >= nums[mid] && target <= nums[high]) 
                    low = mid + 1; 
                
                else //left half of arr
                    high = mid - 1; 
            }
        }
        return -1; //when ele doesnt exist in the array
    }
};

//this will work if the array hasn't been rotated as well

//TC: O(logn) [worst case of binary search since lookup for nums[0]< or > target O(1)]
//SC: O(1)

/*-----------------------------------------------------------------------------------------
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
*/