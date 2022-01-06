class Solution {
public:
    void nextPermutation(vector<int>& nums) {      
//Optimal:
        
        //let i and j act as index1 and index
        int n = nums.size(), i, j;
        int index1, index2;
        //traverse from second last element
    	for (i = n - 2; i >= 0; i--) 
        {
            //get out of loop on the very first instance to preserve that index 
            if (nums[i] < nums[i + 1]) 
            {
                index1=i;
                break;
            }
        }
        //if the index isnt present reverse entire array
    	if (index1 < 0) 
        {
    	    reverse(nums.begin(), nums.end());
    	} 
        //if index is present traverse from the last element till index+1 position hence j>i
        else 
        {
    	    for (j = n - 1; j > index1; j--) 
            {
                //get out of loop on the very first instance to preserve that index 
                if (nums[j] > nums[index1])
                {
                    index2=j;
                     break;
                }
                   
            } 
    	    swap(nums[index1], nums[index2]); //swap the two index's
    	    reverse(nums.begin() + index1 + 1, nums.end()); //reverse array from index+1 to last ele
        }
    }
};

/*
TC:O(n) + O(n) + O(n) [linear traverse from back twice + reversing array
SC: O(1) [no extra space]
*/