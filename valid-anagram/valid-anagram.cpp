class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.length() != t.length()) 
    {
        return false;
    }
        
        int n = s.length();
        int counts[26] = {0}; //to keep track of number of times element occured
        
        for (int i = 0; i < n; i++) 
        { 
//subtract by 'a' to find the index on count array (Given: only lowercase english letters exist)
//if we have char a in S then ASCII a=>97 so a-'a' will be 97-97 = 0th index on count
//['a','b','c',..]  = [0,1,2,...]
            
            counts[s[i] - 'a']++; //if element occurs in S go to that index in count and increment
            counts[t[i] - 'a']--; //if element occurs in S go to that index in count and decrement
        
        //We need to get count value as 0 if element occurs same no of times in S and T
        }
        
        for (int i = 0; i < 26; i++)
        {
            //Traverse through count array to see if all values of count are 0 (0 means anagram)
            
            if (counts[i]!=0) 
            {
                return false;
            }
        }
        return true;
    }
};