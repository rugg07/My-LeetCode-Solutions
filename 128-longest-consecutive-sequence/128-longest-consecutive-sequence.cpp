class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Optimal
        
        //make a hashset. can also put values by for loop
        unordered_set<int> s(begin(nums), end(nums));
	    
        int longestStreak = 0;
	
        for(int i=0; i<nums.size(); i++) 
        {
            //only if one ele lesser than that of arr ele is not present in hashset we do the loop
            if(!s.count(nums[i] - 1)) 
            {
                int currentNum=nums[i]; //keep track of the number
                int currentStreak=1; //since we will be starting our count from that ele
                
                //if one bigger ele is present in hashset 
                while(s.count(currentNum+1)) 
                {
                    currentNum++; //increase the value of current number for while loop 
                    currentStreak++; //increase the count for each consecutive number
                }
            
              longestStreak = max (longestStreak, currentStreak);//find the longest possible streak
            }   
	}
	return longestStreak;
        
    }
};
//TC: O(n) + O(n) + O(n) => O(3n) [traverse arr to put ele in hashset + traverse to check if nums[i]-1 exists in hashSet + to check if (currentNum+1) is present in hashSet ]
//SC: O(n) [unordered hashset in c++ is O(n)]
/*-------------------------------------------------------------------------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //Brute Force:
        
        //no ele in the array 
        if(!size(nums)) 
           return 0;
        
        //sort array in increasing order
        sort(begin(nums), end(nums));
    
        //mas_soFar keeps track of highest consecutive count possible
        //count=1 since we start from 2nd ele we want to start our streak from there 
        int max_soFar = 0, count = 1;

    for(int i = 1; i < size(nums); i++) 
    {	
        if(nums[i] == nums[i - 1]) 
            continue; //duplicate so continue
		
        else if(nums[i] == nums[i - 1] + 1) 
            count++; // consecutive element -> update current streak length
		else 
        {
            max_soFar = max(max_soFar, count);
            count = 1;  // reset current streak length
        }
    }
	return max(max_soFar, count); //max_soFar and count can have different value
    }
};
//TC: O(nlogn) + O(n) [sorting + iteration]
//SC: O(1)

*/
