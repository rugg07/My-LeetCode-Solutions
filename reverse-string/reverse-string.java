class Solution {
    public void reverseString(char[] s) 
    {
        //Same as reversing an integer array
        
        for( int i=0; i<s.length/2; i++) //reverse till n/2 only otherwise string would reverse itself again
        {
            char temp=s[i]; //using an extra charecter variable temp swap the first and last element
            s[i]=s[s.length-i-1]; //decrement from the end depending on the value of i
            s[s.length-i-1]=temp;
        }
    }
}