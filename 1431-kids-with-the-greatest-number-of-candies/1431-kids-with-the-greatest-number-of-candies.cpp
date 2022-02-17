class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        //to return boolean array 
        vector<bool> result;
        
        //use *max_element STL to find max ele in the arr.
        int maxC = *max_element(candies.begin(), candies.end());
        
        
        for(int i=0; i < candies.size(); i++)
        {
            //given in question if after giving extra candies it is true then return true
            if(candies[i]+extraCandies >= maxC)
                result.push_back(true);
            
            else  //if not true then return false
                result.push_back(false);
        }
        return result;
    }
};
//TC: O(n) [traverse arr]
//SC: O(n) [if we count result arr but since its returned it should be O(1) space]