class Solution {
public:
    bool isPalindrome(int x) 
    { //Same method of how you reverse a number. After reversing check if original number is same as the new result if so then return the value to be true
        
        bool flag;
        if(x<0) //if it is a -ve number it will never be a palindrome
        {
            flag=false;
            return flag;
        }
        
        //Initialization
        double result=0; //kept as double since the max number allowed is (8 bytes)*(1byte=8bits)=>64bits
        double remainder=1;
        int temp=x; //x gets used up to find number of digits
        int first=x; //temp gets used up to find the reverse of a number
        int digits=0;
        int k=1; //the position of digit from units place so starting from 1
        
        //count number of digits
        while(x!=0)
        {
            x/=10;
            digits++;
        }
        
        //reverse the number
        while(temp!=0)
        {
            remainder=temp%10;
            result+=remainder*pow(10,digits-k);
            k++;
            temp=temp/10;
        }
        
        //conditional check between new reversed number and the original number
        if(result==first)
        {
            flag=true;
        }
        else
        {
            flag=false;
        }
           return flag;
    }
};

//===============================================================================================//

//This algorithm is O(N) where N is the number of digits. At the same time it is O(lnX), where X is the input value.
