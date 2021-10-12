class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            nums[i]*=nums[i];
        }
        
        sort(nums.begin(), nums.end()); //inbuilt sorting for vector arrays (ALWAYS use .begin() and .end())
        return nums; //return pointer of the array
    }
};