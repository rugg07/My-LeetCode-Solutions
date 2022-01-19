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
//SC: O(n) [hashSet]
