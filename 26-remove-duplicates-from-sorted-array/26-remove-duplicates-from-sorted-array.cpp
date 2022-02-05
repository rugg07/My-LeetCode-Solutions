class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //OPTIMAL: 2-pointer approach
        
        int count=0;
        
        for(int i=1; i<nums.size(); i++) //start from 2nd element (1st index)
        {
            if(nums[i]==nums[i-1]) //if current index element = previous index element
                count++; //increase count for the element
            
            else
                nums[i-count]=nums[i]; //otherwise add nums[i] value to nums[i-count]
        }
       
        return nums.size()-count; //return the the first k values since it goes from 0 to nums.size()-count 
    }
};

//why nums[i-count]? because since its sorted all duplicates will remain together so after going through one element it's count increases.Therefore, i-count gives the next index where no duplicate could be possible 

//0,0,1,1 =>0,1

//TC: O(n) [traversing main arr]
//SC: O(1) [changing in main array itself]

/*----------------------------------------------------------------------------------------
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //BRUTE FORCE: using hashSet
        
        set<int> result;
        
        //insert all values into hashSet (hashSet property - wont accept duplicates)
        for(int i=0; i<nums.size(); i++)
        {
            result.insert(nums[i]);
        }
        
        //inbuilt copy function, store all hashSet values from 0th index in array
        copy(result.begin(), result.end(), nums.begin());
        
        //return hashSet size since program will check from 0..hashSet size if its unique
        return result.size();
    }
};
//TC: O(n) + O(n) = O(2n) = O(n) [store values in hashSet + store in nums arr again]
//SC: O(n) [hashSet to store n ele]
*/