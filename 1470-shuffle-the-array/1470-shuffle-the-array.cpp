class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> result;
        
        //traverse from i = 0 to n=arr.size()/2 [0...n] and push values into arr
        for(int i=0; i < n; i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[n+i]);
        }
        return result;
    }
};
//TC: O(n) [traverse arr]
//SC: O(1) [result array is being returned so not counted]
/*
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
//SC: O(1) [result array is being returned so not counted]

//we do i+n so that we get y1,y2,y3.. i=0 & n=3 in arr.size()=6 we put arr[0] and then 0+3=arr[3] goes into the arr.
*/