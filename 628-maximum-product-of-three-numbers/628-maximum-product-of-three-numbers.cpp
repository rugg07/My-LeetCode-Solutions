class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        //Using Sorting:
        
        int n = nums.size();
		sort(nums.begin(), nums.end());
        
        //since arr is sorted largest ele would be at the end of the arr
        
        //if arr has greater ele in begining like [-100,-98,2,3,4],
        //find product of first 3 and last 3 and see whose product is > using max
		return max(nums[n - 1]*nums[n - 2]*nums[n - 3], nums[0]*nums[1]*nums[n - 1]);
    }
};
//TC: O(nlogn) + O(n)=O(nlogn) [sorting func + 3 ele from beg./end]
//SC: O(1)