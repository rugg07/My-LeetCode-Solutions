class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
//Solution 1: Best Approach
        
        //Once you sort the array all numbers (if duplicates) are grouped together
        sort(nums.begin(), nums.end());
        
        //start from 1st index and look for previous element 
        for(int i=1; i<nums.size(); i++) 
        {
            //to check if duplicate arises and return true on first instance
            if(nums[i]==nums[i-1]) 
            {
                return true;
            }
        }
        return false; //when no duplicate available
    }
};

/*TC: O(NlogN) NlogN because of sorting algorithm being more dominant than O(N) traversal
SC: O(1) not counting the memory used by sort */


/* ---------------------------------------------------------------------------------------------*/

/* Solution 2:
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
        unordered_map<int,int>m; //create a map of the elements and its count
         for(int i=0 ; i<nums.size() ; i++)
         {
            unmap[nums[i]]++; //traverse the array and update for each element
            if(unmap[nums[i]] >= 2) //if the count of that element in the map is >=2 we return true
                return true;
        }
        return false; 
*/