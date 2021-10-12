class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows); 
        for(int i=0; i<numRows; i++)
        {
            r[i].resize(i+1); //number of elements in a row = number of the row so we do i+1
            r[i][0]=1;//first col =1 
            r[i][i]=1;//last col=1
            for(int j=1; j<i; j++) //to find middle ele so we do from j=1 to i since first ele is 1
            {
                r[i][j]=r[i-1][j-1]+r[i-1][j]; //we add the top left and top right ele respective to the current element
            }
        }
        return r; //return array 
    }
};