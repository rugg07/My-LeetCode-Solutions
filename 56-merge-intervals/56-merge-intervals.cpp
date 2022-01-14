class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> result;
        //when there are no intervals
        if(intervals.size()==0) 
            return result;
        
        //if only one interval is present 
        if(intervals.size()<=1) 
             return intervals;
        
        //sort takes O(nlogn) time
        sort(intervals.begin(),intervals.end());
        
        //insert the the the first interval in the result
        result.push_back(intervals[0]);
        
        int j=0; //keep track of intervals in result arr
        
        //Traverse the whole vector .Takes O(n) time
        for(int i=1;i<intervals.size();i++)
        {
            //if intevals are overlapping
            if(result[j][1]>=intervals[i][0]) 
                result[j][1]=max(result[j][1],intervals[i][1]); //take max of both intervals
            
            //else they are not overlapping
            else
            {
                j++; //go to new interval in result array
                result.push_back(intervals[i]); //put directly from intervals arr into result
            }
        }
        return result;
    }
};
//TC: O(n logn) + O(n)[sorting + traversing intervals]
//SC: O(n) [in worst case if no elements merge]
