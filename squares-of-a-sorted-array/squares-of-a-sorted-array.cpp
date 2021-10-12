//Brute force approach
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

//Optimized - (Two Pointer Approach)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start=0; //pointer to first index 
        int end=nums.size()-1; //pointer to last index
        int pointer=nums.size()-1; //pointer for last index of resultant array
        vector<int> result =nums; //make 
        while(start<=end)
        {
            if(abs(nums[start])>abs(nums[end])) //find the bigger number by doing the absolute since square of a number is always +ve
               {
                   result[pointer]=nums[start]*nums[start];//square and put value to the end
                   start++; //increase start position
                   pointer--; //since it points to last index we decrement
               }
               else
               {
                   result[pointer]=nums[end]*nums[end];
                   end--; //decrement end to previous element
                   pointer--;
               }
        }
              return result; //pointer to resultant array
    }
};
