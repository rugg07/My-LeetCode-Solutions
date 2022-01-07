class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//Optimal:
        
        //Traverse through matrix and transpose the elements
        //1st col->1st row, 2nd col->2nd row and so on so we do till j<i
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        //reverse each row to get final rotation
        //each row is marked as matrix[i] and to reverse the entire array we do .begin() & .end()
        for(int i=0; i<matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

//TC : O(n*n) + O(n*n) [transpose + reversing each row]
//SC: O(1) [no extra space used, doing everything in the matrix itself]
