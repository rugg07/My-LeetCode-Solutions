class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
       int n = nums.size();
        
        vector<int> result; //dynamic arr so we add can add 2 ele
        
        unordered_map<int,int> hash; //stores all ele of the array with its index
        
        for(int i=0; i<n; i++)
        {
            if(hash.find(target-nums[i])!=hash.end()) //if ele is found
            {
                //push the second value = j value into result arr and then put i
                result.push_back(hash[target-nums[i]]);  
                result.push_back(i);
                return result;
            } 
            //if ele isnt found store the ele index in hashMap
            hash[nums[i]]=i;
        }
        return result;
    }
};
//TC: O(n) + O(1) + O(1) => O(n) [traverse arr + insert in hashMap + lookup in hashMap ]
//[In c++ unordered_map takes O(n) for lookup and insertion so TC: O(n2)]
//SC: O(n) [storing values in hashMap]

/*--------------------------------------------------------------------------------------*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  
  //BRUTE FORCE: 2 pointers.
  
        int n=nums.size();
        
        vector<int> result(2,0); //to keep track of the pointers
        int k=0; //pointer for result array
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    //store i index first then update k and store j index
                    result[k]=i;
                    k++;
                    result[k]=j;
                }
            }
        }
        return result;
     }
};

TC: O(N^2) [(loop for i=0 to n) x (loop for j=i+1 to n)]
SC: O(1) [we don't count result arr for storing since we need to return vector<int> type arr]
*/