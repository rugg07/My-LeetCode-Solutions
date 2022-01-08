class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//OPTIMAL:        
        
        //if no matrix then directly return false 
        if(matrix.size()==0)
            return false;
         
        int rows=matrix.size();
        //since each row is of same size we find size of first row
        int cols=matrix[0].size();
    
    //we will be performing binary search so we make arr[0][0] as start and arr[n-1][m-1] as end
    //we take 0 to n*m-1 as it represents the index numbers in 2D array
        int start=0; 
        int end=(rows*cols)-1;
        
        while(start<=end){
            int mid = (start+end)/2;
            
    //we do mid/cols and mid%cols to get the new index values that give the resp. value in matrix
            int index1 = mid/cols;
            int index2 = mid%cols;
            
        //then we use conditions of binary search if value<target do mid+1 and if value>target mid-1 
            if(matrix[index1][index2]<target)
                start=mid+1;
            if(matrix[index1][index2]>target)
                end=mid-1;
            if(matrix[index1][index2]==target)
               return true;
        }
        return false;
    }
};

//TC: O(log2 n*m) [we are doing binary search on entire 2D matrix so n*m and not just n]
//SC: O(1) [no extra space]