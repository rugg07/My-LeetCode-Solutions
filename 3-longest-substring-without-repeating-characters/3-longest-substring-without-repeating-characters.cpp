class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //OPTIMAL: to reduce movement of left pointer  
        
        //make frequency array for 256 ASCII charecters and initialise all positions with -1 value
        //string can have only 256 different charecters
        vector<int> unique(256,-1);
        
        int n=s.size();
        
        if(n==0) //no charecters present
            return 0;
        
        int length=0; //current length without repetition in substring
        int max_length=0; //maximum possible length without repetition in substring
        
        //both pointers start from first ele
        int left=0, right=0;
        
        while(right<n)
        {
            //if ele is present the value will be of the index in string.
            if(unique[s[right]]!=-1)
            {
             //We do max so left pointer can jump one ele after the previous repeating ele's pos.
                  left = max(unique[s[right]]+1,left); 
            }
            
//update the position of the ele from the string in the freq array with the right pointer index.   
            unique[s[right]] = right; 
            
            //find max length
            length = right-left+1;
            max_length = max(max_length, length);
            
            right++; //move right pointer to next ele      
        }
        return max_length; 
    }
};
//TC: O(n)+O(1)=>O(n) [right pointer moves n spaces + lookup in freq arr]
//SC: O(256)=>O(1) [set can contain at max all the 256 ASCII charecters. It won't increase more with the size of data.]


/*------------------------------------------------------------------------------------------------

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //BETTER: using 2 pointers and hashSet
        
        //use unordered_set for c++
        unordered_set<char> unique;
        
        int n=s.size();
        
        if(n==0) //no charecters present
            return 0;
        
        int length=0; //current length without repetition in substring
        int max_length=0; //maximum possible length without repetition in substring
        
        //both pointers start from first ele
        int left=0, right=0;
        
        while(left<n && right<n)
        {
            //if s[right] isn't present in the hashSet
            if(unique.find(s[right]) == unique.end())
               {
                   length=right-left+1; //find the current length
                   max_length=max(max_length,length); //see if its the max possible length
                   
                   unique.insert(s[right]);//insert the charecter in hashSet
                   right++;//move the pointer to the next charecter                  
               }
            
            else //if s[left] charecter is present in hashSet
                {
                   unique.erase(s[left]); //remove the charecter from hashSet
                   left++; //move to the next charecter to find new substring 
               }
        }
        
        return max_length; //we want to return the max possible not the current length
    }
};
//TC: O(n)+O(n)=>O(2n) [both left and right pointers need to move n steps assuming last two character are repeating]
//SC: O(256)=>O(1) [set can contain at max all the 256 ASCII charecters. It won't increase more with the size of data.]
*/