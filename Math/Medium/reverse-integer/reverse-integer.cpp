class Solution {
public:
    int reverse(int x) 
    { //Same way of reversing as in normal case only difference here is the constraint and make all data types long otherwise the program exceeds time limit 
      //for a 64 bit number [(1 long = 8bits), given 32bit integer (1 int =4 bits) so 32/4->8 numbers, Thus 8long=64 bits)]
        
        long rem=1; //the remainder 
        long result=0; //the result
        int temp=x; //making a new integer temp that takes the value of x since x is used to find total number of digits
        long digits=0;
        long k=1; //to find the position of the element, cant be 0 else we get an extra 0 on reversing
        while(x!=0)
        {
            x=x/10; //give the quotient each time on division(i.e) it gives us last digit on each iteration 
            digits++;
        }
        while(temp!=0)
        {
            rem=temp%10; //find the remainder left after removing last digit
            result+=rem*pow(10,digits-k); //the result will be calculated based on  digits-k which gives the position of the element from right being 1 and left being n
                                         //(eg: digits=5 and k=1 so that current value would be in the thousands place 1,000 where 1 is the 10^4)
            
            temp=temp/10;//remove last digit on each iteration
            k++;
        }
        if(result<pow(-2,31) || result>(pow(2,31)-1)) //condition given in the question
            return 0;
        return result;
    }
};
