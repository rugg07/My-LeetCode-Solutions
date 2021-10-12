class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements to the begining
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) //if the current element is not zero then move it in front of the last non zero element found
            {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) { //remaining all elements that are blank become 0
            nums[j] = 0;
        }
    }
};