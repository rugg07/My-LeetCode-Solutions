class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int carry=0;
        string result=""; //create new empty string
        int i= num1.size()-1;//point to last index of each string
        int j= num2.size()-1;
        while(i>=0 || j>=0)
        {
            int sum=0; 
            if(i>=0)
            {
                sum += (num1[i]-'0'); //convert string element to ASCII value and see if its in front of ASCII value of '0'
                i--; //go to next element
            }
            if(j>=0)
            {
                sum += (num2[j]-'0');//convert string element to ASCII value and see if its in front of ASCII value of '0'
                j--; //go to next element
            }
            sum+=carry; //sum will always have the value of carry 
            carry=sum/10; //to get the number carried to next element (Quotient)
            sum=sum%10; //remainder left gets added to the new string as normal addition
            result=result+to_string(sum); //adding the remainder here
        }
       if(carry!=0) //Edge case where a carry exists if both strings are of the same length 
        {
           result=result+to_string(carry); //if theres a carry still left then add it to the back of the string
        }
        reverse(result.begin(), result.end()); //since we add all elements to back of the string we need to reverse it to get the final answer
        return result;
    }
};