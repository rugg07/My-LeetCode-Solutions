class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        

 
/*----------------------------------------------------------------------------------------------*/

//Better Approach:
  int n = nums.size();
        
        //to initialize a dynamic array with all values 0
        int *frequency_arr = new int[n]{0};
        
//traverse original array and depending on the value add 1 to value present in index of freq arr
        for(int i=0; i<n ; i++)
        {
            frequency_arr[nums[i]]++;
        }

        //traverse new array and check if value>1. If true then its duplicate element
        for(int i=0; i<n ; i++)
        {
            if(frequency_arr[i]>1)
            {
                return i; //the index in frequency_arr is of the value in orginial array
            }
        }
        return -1;
    }
};

//TC: O(n)+O(n) [traverse org arr + traverse new arr]
//SC: O(n) [new arr]

        
