class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        //BRUTE FORCE: Using Sorting func
        
        int n = nums.size();
		sort(nums.begin(), nums.end());
        
        //since arr is sorted largest ele would be at the end of the arr
        int lastProduct = nums[n - 1]*nums[n - 2]*nums[n - 3];
        
        //if arr has greater ele in begining like [-100,-98,2,3,4],
        int beginingProduct = nums[0]*nums[1]*nums[n - 1];

        //find product of first 3 and last 3 and see whose product is > 
		if(beginingProduct>lastProduct)
            return beginingProduct;
        
        return lastProduct;
    }
};
//TC: O(nlogn) + O(n)=O(nlogn) [sorting func + 3 ele from beg./end]
//SC: O(1)