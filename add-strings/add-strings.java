class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder result=new StringBuilder(); //make a new result string
        int carry=0;
        int i=num1.length()-1; //start from last index of both strings
        int j=num2.length()-1;
        while(i>=0 || j>=0) //going from last index to the first
        {
            int sum=carry; //in the begining sum will be 0 since no addition has taken place and no carry
            //if(i>=0 and j>=0) run for all elements of the loop and assuming one string has more elemts left it then adds those numbers
            
            if(i>=0) //remaining elements present in string 1
            {
                sum+=num1.charAt(i)-'0'; //adding the numbers by converting the to charecter and subtracting '0' from the ASCII equivalent, thus giving us an integer
                i--; //to go to the next iteration/element
            }
            if(j>=0)//remaining elements present in string 2
            {
                sum+=num2.charAt(j)-'0'; //adding the numbers by converting the to charecter and subtracting '0' from the ASCII equivalent, thus giving us an integer
                j--;//to go to the next iteration/element
            }
            result.append(sum%10); //adding the remainder to the end of the result
            carry=sum/10; //to find the value to be transfered to next position
            
        }
        if(carry!=0) //if after doing the addition a carry still remains we add it to the end
             result.append(carry);
        return result.reverse().toString(); //the result string we would get is 431 as in example1 so to get the right value we reverse it
    }
}