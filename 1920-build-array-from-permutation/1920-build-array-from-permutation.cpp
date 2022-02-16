class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        //O(1) Space: Without new array
        
        int n=nums.size();
    
        //STORE THE MOD. VALUES, a = (a+nb)%n
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]+(n*(nums[nums[i]]%n));
        }
        
        //REMOVE THE ARRAY SIZE STORED FROM FIRST LOOP, b = (a+nb)/n
        for(int i=0;i<n;i++)
        {
            nums[i]/=n;
        }
        
        return nums;
    }
};
//TC: O(n) [traversing nums arr]
//SC: O(1) [ans array isnt counted since its returned]

//Eg: we have [0,2,1,5,3,4]. We store the mod values + values in curr index ie.
//when i=1, and n=6, 6*(nums[nums[1]]) => 6*(nums[2]%6) => 6*1 => 6
//nums[i] => nums[1]+6 = 2+6 = 8

//but in second loop on i=2, nums[2]= nums[2]/6 => 8/6 => 1.33 = 1 aprox.

/*----------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
    
        //O(1) Space: using new array
        
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
*/