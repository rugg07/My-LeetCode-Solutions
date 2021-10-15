class Solution {
public:
    string addBinary(string a, string b) {
      int i = a.size()-1, j = b.size()-1; //pointers to the last index of the string
        string sum; //new empty string
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) //we need carry to be greater than one otherwise we will always get 0 as remainder while running the loop
        {
            if (i >= 0) {
                carry += a[i] - '0';
                i -= 1;
            }
            if (j >= 0) {
                carry += b[j] - '0';
                j -= 1;
            }
            sum += (carry % 2) + '0'; //can be 0 but cant be 0 while entering the loop
            carry /= 2;
        }
        reverse(sum.begin(), sum.end()); //reversing the string
        return sum;
    }
};