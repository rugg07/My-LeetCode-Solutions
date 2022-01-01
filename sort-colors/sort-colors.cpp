class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //DUTCH NATIONAL FLAG ALGO.
        
        //make three pointers low,mid,high | low and mid point to first element hence 0
        int low= 0;
        int mid = 0;
        
        //high points to last element 
        int high = nums.size()-1;
        
        //we need to get nums[0...low-1]=0 & nums[high-1...n]=1 all element in middle (mid) = 1
        while(mid<=high)
        {
            switch(nums[mid])
            {
                //if we get 0
                case 0: swap(nums[low],nums[mid]);
                        low++;
                        mid++;
                        break;
                //if we get 1
                case 1: mid++;
                    break;
                //if we get 2
                case 2: swap(nums[mid], nums[high]);
                    high--;
                  break;
                //if none of given numbers
                default: break;
            }
        }
    }
};

//TC: O(N) because we need to traverse till mid<=high only
//SC: O(1) because no extra space is used in this 