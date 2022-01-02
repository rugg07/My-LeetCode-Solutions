class Solution {
public:
    int missingNumber(vector<int>& nums) {
//OPTIMAL
        
        //get the length of array as it is the largest element
       int res = nums.size();
        
        //traverse through array and perform XOR with i and the value in array
    for(int i=0; i<nums.size(); i++){
        
/*a number XOR itself will become 0, any number XOR with 0 will stay unchanged. So if every number from 1...n XOR with itself except the missing number, the result will be the missing number.
    Example:
    1. In [1,2,4] missing is 3
    How?
      res^nums[i] ^ res^i  
     (1^2  ^4)^(1^2^3^4)  = 0^0^3^0 => 3*/
        res ^= i;
        res ^= nums[i];
    }
     return res;   
    }
};

//TC: O(N) traversal of array
//SC: O(1) constant space.

//BRUTE FORCE:
  
/*find total sum until nth element , if number of elements is 3 find sum till 3
 Given that the array will be in range of [0,n] and missing number is between it
     int sum = 0;
        for(int i=1;i<=nums.size(); i++)
        {
            sum+=i;
        }
        
    //traverse through array and keep subtracting from sum. Remaining number is the missing number
        for(int i=0;i<nums.size();i++)
        {
            sum-=nums[i];
        }
        return sum;
}; 
TC:O(N)+O(N) = O(2N) Traversal to add sum + traversal to subtract from sum
SC: O(1) constant space
*/
