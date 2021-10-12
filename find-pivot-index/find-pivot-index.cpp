class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) //no elements
            return -1;

        if (nums.size() == 1) //only one element
            return 0;

        int sum = 0;

        for (int i=0; i<nums.size(); i++) {
            sum += nums[i]; //find total sum
        }

        int left = 0; //leftsum=0
        int right = sum - nums[0]; //totalsum-first element
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) { //as long as ith index is 1,2,3,..,n
                left += nums[i-1]; //increment left sum with previous element
                right -= nums[i];  //decrement right sum with current element from first intialized rightsum
            }
            if (left == right)
                return i; //when both sides sum is equal return the ith index which becomes the pivot
        }

        return -1; //when no conditions pass we return -1

    }
};
