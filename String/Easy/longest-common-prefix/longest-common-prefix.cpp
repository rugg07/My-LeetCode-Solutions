class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) //to check if array of strings is empty
        {
            return 0;
        }
        sort(strs.begin(), strs.end()); //sorts all strings of the array in lexographical order =>[flight,flower,flow]. 
        //(Lexographical order orders the string in ASCII Values of the string in the array and not individual strings 
        //eg: since ASCII value i of flight < o of flower so flight comes first and since flower has er in the end whilst flow doesnt so flower comes first then flow )
        
        string result=strs[0]; //this takes the value of the first string after sorting(flight)
        for(int i=1; i<strs.size(); i++) //to traverse 1 string in the array at a time
        {int j;
            for(j=0; j<strs[i].size(); j++) //traversing each index wise for the string
            {
                if(result[j]!=strs[i][j]) //if index of result string and the respective strs string is same or not 
                { 
                    break; //when not same then break
                }
            }
        result =result.substr(0,j); //if same then add the substring till the jth position(until j loop didn't break)
        if(result == "")
        {
            return ""; //if result is still an empty string print it
        }
        }
        
        return result;
    }
};
