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
        double result=0;
        double remainder=1;
        int temp=x;
        int first=x;
        int digits=0;
        int k=1;
        while(x!=0)
        {
            x/=10;
            digits++;
        }
        while(temp!=0)
        {
            remainder=temp%10;
            result+=remainder*pow(10,digits-k);
            k++;
            temp=temp/10;
        }
        
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