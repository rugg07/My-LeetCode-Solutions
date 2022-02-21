class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        //In-place
        
		// to store the pair of numbers in right half of the original array
        for(int i = n; i < nums.size(); i++)
            nums[i] = (nums[i] * 1024) + nums[i - n];
        
        int index = 0;
		
        // to retrive values from the pair of numbers,
        //placing those retrieved value at their desired position
        for(int i = n; i < nums.size(); i++, index += 2)
        {
            nums[index] = nums[i] % 1024;
            nums[index + 1] = nums[i] / 1024;
        }
        
        return nums;   
    }
};
//TC: O(n) [traverse arr]
//SC: O(1) [being done in-place]

/*See the reason in doc*/

/*---------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        
        //since n will divide the array into 2 equal halfs.
        //traverse from i = 0 to arr.size()/2 [0...n/2] and push values into arr
        //push values from [n/2+1...n] ie. second half od the arr
        for(int i=0; i<nums.size()/2; i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[i+n]); //same as n/2+i where n is array size.
        }
        return result;
    }
};
//TC: O(n) [traverse arr]
//SC: O(n) [since result arr is being returned so not counted and TC should be O(1)]

//we do i+n so that we get y1,y2,y3.. i=0 & n=3 in arr.size()=6 we put arr[0] and then 0+3=arr[3] goes into the arr.

*/