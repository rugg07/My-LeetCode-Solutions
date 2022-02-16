class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        vector<int> ans;
        
        ans.resize(nums.size()); //should be of same size as nums array
        
        for(int i=0; i<nums.size();i++)
        {
            ans[i]=nums[nums[i]]; //given in question
        }
        return ans;
    }
};
//TC: O(n) [traversing nums arr]
//SC: O(1) [ans array isnt counted since its returned]