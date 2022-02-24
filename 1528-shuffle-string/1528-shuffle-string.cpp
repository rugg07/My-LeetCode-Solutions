
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        //OPTIMAL: Cyclic sort - swapping (no extra space)
        
        for(int i=0; i<indices.size(); )
        {
            //if value same then no need to change charecter pos in string s
            if(indices[i]==i) 
                i++;
            
            //first swap the pos. of charecters for [i] and [indices[i]]
            //then swap btw indices[i] & indices[indices[i]] 
            //to put indices[i] item in its proper location in indices arr.
            else 
            {
                swap(s[i],s[indices[i]]);
                swap(indices[i],indices[indices[i]]);
            }
        }
        return s;
    }
};
//TC: O(n) [traverse indices and string s together]
//SC: O(1) [no extra space]

/*----------------------------------------------------------------------------------------
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        //BRUTE FORCE: using extra space
        
        string result = s; //copy original string
        for(int i =0; i < indices.size(); i++)
        {
            //for the no. present in indices arr, put the ith charecter in result string
            result[indices[i]] = s[i]; 
        }
        return result;
    }
};
//TC: O(n)+O(n)=O(2n)=>O(n) [travere string + traverse arr]
//SC: O(n) [for string but since string is returned it would be O(1)]
*/