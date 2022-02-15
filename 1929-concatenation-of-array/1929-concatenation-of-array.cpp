class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> newnums;
        
        //if we dont give an initial size we can store ele from i+n index
        //has to be 2*n (given)
        newnums.resize(2*n);
        
        for(int i=0; i<nums.size();i++)
        {
            newnums[i]=nums[i];
            newnums[i+n]=nums[i];
        }
        return newnums;
    }
};
//TC: O(n) [traverse nums arr]
//SC: O(1) [we dont count newnums arr since its being returned]


/*--------------------------------------------------------------------------------------
We can update the org arr itself and return it. Since org arr is of vector type int, this means its a dynamic arr and can have more ele added.

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
*/