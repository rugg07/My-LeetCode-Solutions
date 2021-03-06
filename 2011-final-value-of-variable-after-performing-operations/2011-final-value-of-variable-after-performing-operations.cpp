class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
      int ans=0;
      for(int i=0;i<operations.size();i++)
         {
            if(operations[i]== "X++" || operations[i]== "++X" )
                ans++;
              
            else //if it is "X--" or "--X"
                ans--;
         }
      return ans;
    }
};
/*----------------------------------------------------------------------------------------
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int result=0; //final value being returned
        
        for(int i=0; i<operations.size(); i++)
        {
            if(operations[i]=="--X") //if arr[i] is "--X"
                --result;
            if(operations[i]=="X--") //if arr[i] is "X--"
                result--;
            if(operations[i]=="++X") //if arr[i] is "++X"
                ++result;
            if(operations[i]=="X++") //if arr[i] is "X++"
                result++;
        }
        return result;
    }
};
//TC: O(n) [traverse arr]
//SC: O(1) 
*/