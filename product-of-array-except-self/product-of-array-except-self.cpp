class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        
        //Make 3 loops for 3 arrays
        //1.product on the left side of nums[i]
        //2.product on the right side of nums[i]
        //3.final product
        
        //1. Left side product array
        int left_product[n];
        left_product[0]=1; //first element will be 1 else it will take random value
        
        //2. Right side product array
        int right_product[n];
        right_product[n-1]=1; //last element will be 1 else it will take random value
        

//return type is vector<int> we initialize entire array of size n with 1 else it doesnt give output
         vector<int> final_product(n,1);
        
        //Products of left side
        for(int i=1; i<n; i++)
        {
            //we start from 1st index and multiply with value of last index for both arrays
            left_product[i]=left_product[i-1]*nums[i-1];
        }
        
        //Products of right side
        for(int i=n-2; i>=0; i--)
        {
        //we start from 2nd last index and multiply with value of the succeding index of both array
            right_product[i]=right_product[i+1]*nums[i+1];
        }
        
        //Product of final array
        for(int i=0;i<n;i++)
        {
            
        //Multiply on both sides
            final_product[i] = left_product[i]*right_product[i];
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