class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        
//final product array
//return type is vector<int> we initialize entire array of size n with 1 else it doesnt give output
        vector<int> final_product(n,1);
        final_product[0]=1; //first element will be 1 else it will take random value
        
           
        //Products of left side
        for(int i=1; i<n; i++)
        {
            //we start from 1st index and multiply with value of last index for both arrays
            final_product[i]=final_product[i-1]*nums[i-1];
        }
        
        
        //Right side product in final_product array
        int right_product=1; //last element will be 1 else it will take random value
        
        //Products of right side
        for(int i=n-1; i>=0; i--)
        {
            final_product[i]=final_product[i]*right_product;
            right_product*=nums[i]; 
            //right_product increases with each element going from right to left
        }
        
       return final_product;
    }
};


/*
If allowed to use division:-
    - Find total product of entire array
    - Using new array traverse and keep dividing from total product
    - eg: If total product=24 [24/1, 24/2, 24/3, 24/4]=> [24,12,8,6]
    
    TC: O(2N)=> O(N)
    SC: better than above method as less number of arrays are being used
    
*/