class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //OPTIMAL: 2-pointer + vector to store values as triplets
        
        if(nums.size()==0||nums.size()<3) // Atleast three elements needed for a triplet
            return {};
        
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> res; //stores unique triplets
        
        // moves for a
        
        // go till 3rd last ele so that,
        // 2nd last ele & last ele become 2nd last & last ele's of triplet
        //[...3rd,2nd,n-1]  => {3rd, 2nd, n-1} triplet
        for (int i = 0; i < nums.size()-2; i++) 
        {
            // if it's the 1st ele || if its after 0th index & it's NOT duplicate ele 
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) 
            {
                //2-pointer approach
                  
                int low = i+1; // 2nd ele
                int high = nums.size()-1; // last ele
                
                int sum = 0 - nums[i]; // sum = 0-a => -a, because b+c=-a=>sum
                
                // same as 2 sum problem move till low doesnt overtake high
                while (low < high) 
                {
                    if (nums[low] + nums[high] == sum)  // if the ele are found
                    {
                        vector<int> temp; //push the 3 values into arr to act as triplet
                        
                        temp.push_back(nums[i]); 
                        temp.push_back(nums[low]); 
                        temp.push_back(nums[high]); 
                        
                        res.push_back(temp); //push this entire arr as triplet in org. arr
                        
                        //ignoring duplicates
                        
                        while (low < high && nums[low] == nums[low+1]) //duplicate for low
                            low++;
                        
                        while (low < high && nums[high] == nums[high-1])//duplic. for high
                            high--;
                        
                        low++; high--; //if duplicates/none then also we move to next ele
                    }
                    
                    else if (nums[low] + nums[high] < sum) //sum < -a (which is needed)
                        low++; //since sorted arr increasing low takes us to higher value
                   
                    else 
                        high--;
               }
            }
        }
        return res;
    }
};
//TC: O(n*n)=O(n^2) [loop to find -a * loop for two pointer approach that= O(n) for n ele]
//SC: O(m) [creating new vector to store values as triplets before pushing in main arr]
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      
       // BETTER: using 2 loops + hashMap + hashSet
        
        int n = nums.size();
        
        vector<vector<int>>ans; //main vector being returned
        
        if(n==0||n<3) // Atleast three elements needed for a triplet
            return ans;
        
        unordered_map<int,int>ump; //to store the count for the ele's 
        
        for(int k=0; k<nums.size(); k++)
        {
            ump[nums[k]]++; //update the count for each 
        }
        
        set<vector<int>>s; //to store the triplets, also prevents duplicates storage
        
        for(int i=0;i<n;i++)
        {
            ump[nums[i]]--; //reduce it since its used as a
            for(int j=i+1;j<n;j++)
            {
                ump[nums[j]]--; //reduce it since its used as b
                int c = -1*(nums[i]+nums[j]); //c = -(a+b)
                 
                //check if the required c is present in hashMap and if the value stored >0
                if(ump.find(c)!=ump.end()&&ump[c]>0) 
                {
                        //store triplet in new vector array.
                        vector<int>temp = {nums[i],nums[j],c};
                        sort(temp.begin(),temp.end()); //sort the array
                        s.insert(temp); //put the new triplet into hashSet
                }
                ump[nums[j]]++; //update since we reduced in the begining
            }
            ump[nums[i]]++; //update since we reduced in the begining
        }
        
        ans.assign(s.begin(),s.end());//put all values of hashSet into the main vector arr
        return ans;
    }
};

//1. we do a+b+c=0 but since we have nums[i] & nums[j] acting as a&b, we do c=-(a+b)
//2. to prevent it from acting as duplicates when we check for the formula of c=-(a+b) 
//we reduce its hash value (count) before being used, i.e we do hashMap[nums[i]]-- or hashMap[nums[j]]--
//3. it will act as duplicate when we check ump[c]>0 keeps being true

//TC: O(n) + O(n^2*log m) = O(n^2) [put count value into hashMap + traverse to the last ele from 0th & 1st index * insert of triplet into hashSet]
//SC: O(m)+O(n)+O(n) = O(3n) =O(n) [hashMap + hashSet + vector arr made to store triplet (not main vector being returned)]
*/

/*----------------------------------------------------------------------------------------class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      
       // Brute Force: using 3 loops and hashSet
        
        int len=nums.size();
        
        if(len==0 || len<3) // Atleast three elements needed for a triplet
            return {}; //return empty array 
        
        //Set stores unique elements only (duplicate triplets not added)
        //vector<int> because that's the type needed while returning
        set<vector<int>> s;
        
        //sort to make it simpler
        sort(nums.begin(),nums.end());
        
        // Compare all cases of group of three elements for their sum=0 
        for(int i=0;i<len-2;i++) // i= 0 to n-2 as it would be 3rd last ele 
        {
            for(int j=i+1;j<len-1;j++) // j= i+1 to n-1 as it would be 2nd last ele 
            {
                for(int k=j+1;k<len;k++) // k= j+1 to n as it would be last ele 
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        // in {} since we want to store it as a triplet
                        s.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        
        // Insert all unique triplets in result vector
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};
//TC: O(n^3 logm) [3 loops traversing through arr * insertion of triplets in hashSet]
//SC: O(m) [hashSet, we dont count vector array made as it is needed to return]
*/