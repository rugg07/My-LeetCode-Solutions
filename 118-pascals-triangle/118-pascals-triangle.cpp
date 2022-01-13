class Solution {
public:
    vector<vector<int>> generate(int numRows) {
//Problem 1: Print Pascal Triangle
        //make dynamic array of
        vector<vector<int>> r(numRows); 
        for(int i=0; i<numRows; i++)
        {
            //number of rows = number of columns = no.of elements (So we resize the empty vector r)
            r[i].resize(i+1);  //since we start from i=0 so we do resize(i+1) to give one extra ele
                               //0th row will have  i=0 => resize(0+1) => 1 ele
            
            r[i][0]=r[i][i]=1;//first ele of each col = last ele of each col = 1
            
            //traverse from 1st col to second last col. since first and last ele are 1 of each row
            for(int j=1; j<i; j++) 
            {
                //we add the top left and top right ele respective to the current element
                //egr[2][1]=r[1][0]+r[1][2]=>1+2=>3
                r[i][j]=r[i-1][j-1]+r[i-1][j]; 
            }
        }
        return r; //return array 
    }
};
//TC: O(n^2)[since we are computing each row and column]
//SC: O(n^2)[we will need to store pascal triangle]
//.resize() add/deletes the number of elements inside a vector