class Solution {
public:
    int fib(int n) {
      
        if(n==0)
       {
           return 0; //use 0 
       }
        if(n==1)
        {
            return 1; //use 1
        }
        
            return fib(n-1)+fib(n-2); //instead of taking another element equating to this equation and returning we directly return the value in this way
    }
}; 

//Time Complexity - O(2^N)
//Space Complexity - O(N) given the function call stack size
