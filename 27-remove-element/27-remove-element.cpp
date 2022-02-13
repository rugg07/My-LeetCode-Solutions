//SAME AS: Remove Duplicates from Sorted Array - 26

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       
        //OPTIMAL: 2 pointer
        
        int count=0;
        
        sort(nums.begin(),nums.end()); //keeps array in increasing order
        
        for(int i=0; i<nums.size(); i++)
        {
           if(nums[i]==val) //if its the duplicate (same as val) increase count
               count++;
           
            //only when its not same ele otherwise its performed for every iteration
            else  
                nums[i-count]=nums[i]; //put ele in the begining
        }
        
        return nums.size()-count; //return the the first k values, [0...n-count]
    }
};

//why nums[i-count]? because since its sorted all duplicates will remain together so after going through one element it's count increases.Therefore, i-count gives the next index where no duplicate could be possible 

//0,0,1,1 =>0,1

//TC: O(n) [traverse arr]
//SC: O(1)