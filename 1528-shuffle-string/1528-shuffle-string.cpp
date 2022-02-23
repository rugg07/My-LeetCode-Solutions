class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
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