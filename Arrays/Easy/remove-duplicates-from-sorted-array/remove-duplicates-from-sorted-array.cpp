class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=0;
        for(int i=1; i<nums.size(); i++) //start from 2nd element (1st index)
        {
            if(nums[i]==nums[i-1]) //if current index element = previous index element
            {
                count++; //increase count for the element
            }
            else
            {
                nums[i-count]=nums[i]; //otherwise add nums[i] value to nums[i-count]
            }
        }
       
        return nums.size()-count; //return the the first k values since it goes from 0 to nums.size()-count 
    }
};

//why nums[i-count]? because since its sorted all duplicates will remain together so after going through one element it's count increases.Therefore, i-count gives the next index where no duplicate could be possible 

//0,0,1,1 =>0,1
