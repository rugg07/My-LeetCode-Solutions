class Solution {
public:
    int trap(vector<int>& height) {
       
        //OPTIMAL: using Prefix & Suffix arr (to replicate left and right max)
        
        int n=height.size();
        
        //make array storing max value for left side and keep iterating through to the end
        int prefix[n]; 
        
        prefix[0] = height[0]; //let first ele store the value of 0th index of height
        for(int p=1; p<height.size(); p++)
        {
            //compare current height ele with previous prefix arr ele
            //if we reverse it wont be possible as prefix would point to null then
            prefix[p]=max(prefix[p-1],height[p]);
        }
        
        //make array storing max value for right side and keep iterating through to 0
        int suffix[n];
        
        //store the last ele in suffix from height
        suffix[n-1] = height[n-1];
        for(int s=height.size()-2; s>=0; s--)
        {
            //compare current height ele with succeding suffix arr ele
            suffix[s]=max(suffix[s+1],height[s]);
        }
        
        int result=0;        
        for(int i=0; i<height.size(); i++)
        {
            //using the same formula which we use in brute force
            result+= min(prefix[i], suffix[i])-height[i];
        }
        
        return result;
        
    }
};

/** do prefix[p]/suffix[s] before height[i-1]/[i+1] to prevent wrong output **/

//TC: O(n)+O(n)+O(n) = O(3n) = O(n) [prefix arr + suffix arr + result in main arr]
//SC: O(n)+O(n) = O(2n) =O(n) [prefix arr + suffix arr]

/*---------------------------------------------------------------------------------------
class Solution {
public:
    int trap(vector<int>& height) {
       
        //BRUTE FORCE: using the formula min(leftmax, rightmax)-height[i]
        
        int result=0;
       
        
        for(int i=0; i<height.size(); i++)
        {
            //initialize in loop to update for each iteration of i
             int leftmax=0;
             int rightmax=0;
            
            //find left max going from current i to 0
           for(int l=i; l>=0; l--)
               leftmax = max (leftmax, height[l]);
            
            //find right max going from current i to the end
            for(int k=i; k<height.size(); k++)
                rightmax = max (rightmax, height[k]);
            
            //result would be min of left and right - the height(value) of current i
            result+= min(leftmax, rightmax)-height[i];
        }
        
        return result;
    }
};
//TC: O(n^2) [in each iteration of i (traverse left side * traverse right side)]
//SC: O(1)
*/