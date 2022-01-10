class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
//Optimal: Boyes Moore Voting Algorithm
        
        //keep two variable to store the major ele 
        int num1=-1; int num2=-1;
        //keep two variables to keep count of the major ele
        int count1=0; int count2=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            //if the ele is same as what num1 holds increase its count i.e count1
            if(nums[i]==num1) 
                count1++;
            
            //if the ele is same as what num2 holds increase its count i.e count2
            else if(nums[i]==num2)
                count2++;
            
            //if the ele is not same as num1 or num2 but if count1 is still 0 then num1=ele
            else if(count1==0)
            {
                num1=nums[i];
                count1=1;
            }
            
            //if the ele is not same as num1 or num2 but if count2 is still 0 then num2=ele
            else if(count2==0)
            {
                num2=nums[i];
                count2=1;
            }
            
            //neither num1/num2=ele and count1/count2!=0 then reduce count1&&count2 by 1
            else{
                count1--;
                count2--;
            }
        }
        
        //make a new vector<int> array since it requires a vector<int> return type
        vector<int> ans;
        count1=0, count2=0; //make count1 & count2 0 again to count instances of num1 and num2
        
        //traverse arr again and see how many times num1 and num2 occur by increasing their count
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==num1)
                count1++;
            else if(nums[i]==num2)
                count2++;
        }
        
//if either count1 or count2 has value greater than n/3 [same as Ln/3] push it into the array using inbuilt .push_back() function
        if(count1>nums.size()/3)
            ans.push_back(num1);
        if(count2>nums.size()/3)
            ans.push_back(num2);
        
        //return the array
        return ans;
    }
};

//TC: O(n)+O(n) [traverse arr to find two major ele + traverse arr to see if > Ln/3 ]
//SC: O(1)