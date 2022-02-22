class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        //OPTIMAL: hashMap
        int count=0;
        unordered_map<int,int>result;

        for (int i=0; i<nums.size(); i++) 
        {
            //if ele exists already it the hash stored for it gets added to count
            count += result[nums[i]];
            //we update the hash Value for that ele in hashMap
            result[nums[i]]++;
        }
        return count;
    }
};
//TC: O(n) [traverse arr]
//SC: O(n) [hashMap]

/*---------------------------------------------------------------------------------------
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        //BRUTE FORCE
        int count=0;
        
        for(int i=0; i<nums.size();i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
              if(nums[i]==nums[j])
                count++;
            }    
        }
        return count;
    }
};
//TC: O(n^2) [traversing array for each ele from i and j=i+1]
//SC: O(1)
*/