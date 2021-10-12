class Solution {
    public int[] plusOne(int[] digits) {
        int n=digits.length; //length of array 
        for(int i=n-1; i>=0; i--) //go to the last element (Think of it is normal math addition)
        {
            if(digits[i]<9) //if the element < 9
            {
                digits[i]++; //increase by one
                return digits; //directly return the value and end the function
            }
            digits[i]=0; //if direction > 9 then ith value becomes 0
            
        }
      
        int[] newNumber= new int [n+1]; //TEST CASE:if the number is just 9
                                        //if it was [9,9,9,9,...] it goes in the above loop
        newNumber[0]=1;//Make the first element = 1 
        return newNumber;
    }
}