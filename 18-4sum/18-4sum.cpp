class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//OPTIMAL:
        
       //store the unique quads 
       vector<vector<int>> result;
        
        //if array is empty return the main result vector since its empty
        if (nums.empty())
            return result;
        
        int n = nums.size(); 
        sort(nums.begin(),nums.end()); //sort the array
    
        for (int i = 0; i < n; i++) 
        {       
            for (int j = i + 1; j < n; j++) 
            {
              //new target to be searched for in right side of array 
                int new_target = target - nums[j]- nums[i];
            
                int left = j + 1;
                int right = n - 1;
            
                while(left < right) 
                {
                    //value used to see where our new_target will be since array is sorted
                    int two_sum = nums[left] + nums[right];
                
                    if (two_sum < new_target) //target is on right side since its bigger
                        left++;
                
                    else if (two_sum > new_target) //target is on left side since its smaller
                        right--;
                
                    else 
                    {
                        //make new vector array of size 4 with all ele initialized to 0
                        vector<int> quadruplet(4, 0);
                        
                        //store values of all pointers
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        
                        //Add the new quad to the main vector
                        result.push_back(quadruplet);
                    
                        //to prevent duplicate values to go in quadruple[2] from Left pointer.
                        while (left < right && nums[left] == quadruplet[2]) 
                            ++left;
                    
                        //to prevent duplicate values to go in quadruple[3] from Right pointer.
                        while (left < right && nums[right] == quadruplet[3])
                            --right;
                
                    }
                }
                
                //prevent j from going over duplicates and eventually storing in quad[1]
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
        
            //prevent i from going over duplicates and eventually storing in quad[0]
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        
        }
        return result;         
    }
};
//TC: O(n^3)[(2 loops i*j) x (left pointer and right pointer that at max move till n)]
//SC: O(1) [we don't count space complexity of vector used to return ans] 




/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//BRUTE FORCE:
        
        //create a hashSet to prevent duplication of quads
        set<vector<int>> unique_quads;
        
        //sort the array
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size();i++)
        {
            for(int j=i+1; j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                    //find the number to be searched for in right half of the array
                    int new_target=(long long)target-(long long)nums[i]-(long long)nums[j]-(long long)nums[k];
                   //if the new target is found through inbuilt binary_search() STL
                   if(binary_search(nums.begin()+k+1,nums.end(),new_target))
                   {
                       //create a vector to add the quad in
                            vector<int> quads;
                            quads.push_back(nums[i]);
                            quads.push_back(nums[j]);
                            quads.push_back(nums[k]);
                            quads.push_back(new_target);
                       
                            //sort the newely added quad
                            sort(quads.begin(),quads.end());
                       
                            //add the quad into the hashSet
                            unique_quads.insert(quads);
                        }
                }
            }
        }
        
        //make a new datastructure and add all unique quads from hashSet
        vector<vector<int>> result(unique_quads.begin(),unique_quads.end());
        return result;  
    }
};
//TC:O(n^3logn)+O(nlogn)[3 loops for i,j,k * binary search for right half of array in k loop+sort]
//SC: O(1) 
*/