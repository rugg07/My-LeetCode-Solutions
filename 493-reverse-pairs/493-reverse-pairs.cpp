class Solution {
public:
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        int count=0; //total count
        int left = low; //this points to first index of LEFT array.
        int right = mid + 1; //this points to first index of RIGHT array.
        
        //Traverse both arrays at same time
        while(left <= mid && right <= high)
        {
            if(nums[left] >  2LL * nums[right])
            {
                //all elements present in LEFT array btw left and mid pointers. Hence left+1
                count += (mid - left + 1); 
                right++; //since condition is T pair can be made and we go to next ele in RIGHT arr
            }
            else
            { left++;} //Since no pair can be made we move onto next ele in LEFT arr
        }
        
        //sort the final array between low to high. Hence we do .begin()+low or +(high+1)
        // can also be writeen as (i=low; i<high+1 ;i++)
         sort(nums.begin() + low, nums.begin() + high + 1);
/*        
       //merge the sorted elements in temp arr
        vector<int> temp; //temp array to store the sorted array.
        
        int left = low; //first index of left array
        int right = mid+1; //first index of right array
        
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[high])
            {temp.push_back(nums[left++]);}
            else
            {temp.push_back(nums[right++]);}
        }
        
        //all elements of right arr have been used up, put remaining LEFT arr ele into temp arr
        while(left<=mid)
        {temp.push_back(nums[left++]);}
        
        //all elements of left arr have been used up, put remaining RIGHT arr ele into temp arr
        while(right<=high)
        {temp.push_back(nums[right++]);}
        
        //put all elements from temp array into original array
        for(int i=low; i<high+1; i++)
        {
            //i-low to get index in temp arr as low would have current value from LEFT array 
            nums[i]=temp[i-low]; 
        }
*/
        
        return count;
    }
    
    int mergeSort(vector<int>& nums,int low, int high)
    {
        if(low>=high)
            return 0; //shouldnt be possible
        
        int mid=(low+high)/2;
        
        //break the array into 2 parts. 
        //LEFT array = arr[low...mid]
        int inversion = mergeSort(nums, low, mid);
        //RIGHT array = arr[mid+1...high]
        inversion+= mergeSort(nums, mid+1, high);
        //merge final array arr[low...high]
        inversion+= merge(nums,low,mid,high);
        
        return inversion;
    }
    
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums, 0, nums.size()-1);
    }
};
//TC: O(nlogn) + O(n) + O(n) [TC of merge sort + merge func + count func]. 

/*In count func i & j at max move n1+n2 no. of steps hence O(n1+n2)= O(n). If j started from first position everytime it would have been n*n but since j starts from its previous index only we get O(n)*/
 
//SC: O(n) [temp arr] 

//-------------------------------------------------------------------------------------------------
/*
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        //Brute force
        
//keep two pointers. One pointer stays at one element while the other traverses through the array.
//Each time the condition nums[i]>2*nums[j] we increase our count
        int i, j;
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
             //2LL means 2 in Long Long format.
            //we do this to avoid overflow. because 2*nums[j] would be of int type as both are int
                if(nums[i]>2LL* nums[j])
                    count++;
            }
        }
        return count;
    }
};
//TC: O(n*m) [traversing i * traversing j]
//SC: O(1) 
*/